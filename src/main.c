#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <dirent.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>

#define __VERSION_STR "0.0.1 (12.10.2024)"
#define __PROJECT_LOCATION "location_here"
#define __STRCASECMP strcasecmp

void
extract_dir_errno ( int status )
{
  switch ( status )
    {
    case EACCES:
      printf ( "\n%s\n", "NO PERMISSION TO MAKE DIR" );
    case EEXIST:
      printf ( "\n%s\n", "DIR ALREADY EXISTS" );
    case ENAMETOOLONG:
      printf ( "\n%s\n", "DIR NAME TOO LONG" );
    case EROFS:
      printf ( "\n%s\n", "ATTEMPTING TO CREATE DIR ON READ ONLY FILE SYSTEM" );
    case ELOOP:
      printf ( "\n%s\n", "LOOP FOUND IN SYMBOLIC LINKS" );
    case EMLINK:
      printf ( "\n%s\n", "LINK COUNT MAY EXCEED BOUNDS" );
    case ENOENT:
      printf ( "\n%s\n", "PATH DOES NOT MENTION VALID DIR OR PATH OR IS A EMPTY STRING" );
    case ENOSPC:
      printf ( "\n%s\n", "NOT ENOUGH SPACE ON DISK" );
    case ENOTDIR:
      printf ( "\n%s\n", "PATH PREFIX IS NOT A DIR" );
    default:
      printf ( "\n%s\n", "Denied Access Unknown OP Code." );
    }
}

int
dir_exists ( const char* path )
{
  DIR* dir = opendir ( path );
  if ( dir )
    {
      closedir ( dir );
      return 1;
    }
  return 0;
}

int
dir_create ( const char* path )
{
  return mkdir ( path, 0777 );
}

int
str_isalpha_excludes ( const char* source, char exclude )
{
  const char* copy = source;
  do
    {
      if ( !isalnum ( *copy ) )
        {
          if ( ( *copy == exclude ) == 0 )
            return 0;
        }
      copy++;
    }
  while ( *copy != '\0' );

  return 1;
}

int
str_empty ( const char* src )
{
  return src == NULL || src[ 0 ] == '\0';
}

int
dup_source ( const char* path, const char* projectType )
{
  // Ok generate and copy project data here
  // use flag -R
  printf ( "\n%s\n", "Generating sources..." );

  if ( str_empty ( path ) || str_empty ( projectType ) )
    {
      printf ( "%s\n", "Sources cannot be empty" );
      return 1;
    }

  int result;
  if ( !dir_exists ( ( const char* )path ) )
    {
      if ( ( result = dir_create ( ( const char* )path ) ) )
        {
          printf ( "%s\n", "Failed to create directory." );
          if ( result != 0 )
            extract_dir_errno ( result );
          return 1;
        }
    }

  char cmd[ 512 ];
  memset ( cmd, 0, 512 );

  strcat ( cmd, "cp -Rv " );
  strcat ( cmd, __PROJECT_LOCATION );
  strcat ( cmd, projectType );
  strcat ( cmd, "/*" );
  strcat ( cmd, " " );
  strcat ( cmd, path );

  printf ( "Executing: %s\n", cmd );
  return system ( cmd );
}

int
select_paths ( char* path_ptr, char* name_ptr )
{
  printf ( "\n%s\n", "Name of Project:" );
  printf ( "%s", ">>> " );
  scanf ( "%s", name_ptr );

  if ( str_empty ( ( const char* )name_ptr ) )
    {
      printf ( "\n%s\n", "Name cannot be empty" );
      return 0;
    }

  if ( !str_isalpha_excludes ( ( const char* )name_ptr, '_' ) )
    {
      printf ( "\n%s\n", "Invalid symbols detected." );
      return 0;
    }

  printf ( "\n%s\n", "Path to project (Desktop or Documents):" );
  printf ( "%s", ">>> " );
  scanf ( "%s", path_ptr );

  if ( str_empty ( ( const char* )path_ptr ) )
    {
      printf ( "\n%s\n", "Path cannot be empty" );
      return 0;
    }

  if ( !str_isalpha_excludes ( ( const char* )path_ptr, '_' ) )
    {
      printf ( "\n%s\n", "Invalid symbols detected." );
      return 0;
    }

  if (
      __STRCASECMP ( ( const char* )path_ptr, "desktop" ) != 0 && __STRCASECMP ( ( const char* )path_ptr, "documents" ) != 0 )
    {
      printf ( "\n%s\n", "Invalid path detected." );
      return 0;
    }

  return 1;
}

int
main ( int argc, const char* argv[] )
{
  /* Command Line Arguments */
  if ( argc > 1 )
    {
      if ( strcmp ( argv[ 1 ], "-v" ) == 0 )
        printf ( "%s%s\n", "ClangStart Build: ", __VERSION_STR );
      return 0;
    }

  int option;

  char buffer[ 256 ];
  char path[ 256 ];
  char name[ 256 ];

  printf ( "\n%s\n\n", "Welcome to ClangStart. Select an option:" );
  printf ( "%s\n", "  1) Create new C Makefile Project" );
  printf ( "%s\n", "  2) Create new C++ Makefile Project" );
  printf ( "%s\n", "  3) Create new C CMake Project" );
  printf ( "%s\n", "  4) Create new C++ CMake Project" );
  printf ( "%s\n", "  0) Quit Program" );

  printf ( "\n%s ", ">>> " );
  scanf ( "%d", &option );

  if ( option < 0 || option > 4 )
    {
      printf ( "\n%s\n", "Invalid option given. Aborting..." );
      return -1;
    }

  if ( option == 0 )
    {
      printf ( "\n%s\n", "Terminating..." );
      return 0;
    }

  if ( !select_paths ( path, name ) )
    {
      printf ( "\n%s\n", "Invalid arguments. Aborting..." );
      return -1;
    }

  /* Quickly convert to the proper locations */
  path[ 0 ] = toupper ( ( unsigned char )*path );

  /* Update relative location via temporary buffer */
  snprintf ( buffer, 256, "%s/", getenv ( "HOME" ) );

  strcat ( buffer, path );
  strcat ( buffer, "/" );
  strcat ( buffer, name );

  memcpy ( path, buffer, 256 * sizeof ( char ) );

  printf ( "\n%s\n", "[SELECTED CHOICES]:" );
  printf ( "%s%s\n", "Project Name: ", name );
  printf ( "%s%s\n", "Project Path: ", path );

  if ( option == 1 )
    {
      if ( dup_source ( path, "C_Makefile_Project" ) )
        {
          printf ( "%s\n", "Failed to generate sources. Aborting..." );
          return -1;
        }
    }

  if ( option == 2 )
    {
      if ( dup_source ( path, "Cpp_Makefile_Project" ) )
        {
          printf ( "%s\n", "Failed to generate sources. Aborting..." );
          return -1;
        }
    }

  if ( option == 3 )
    {
      if ( dup_source ( path, "C_CMake_Project" ) )
        {
          printf ( "%s\n", "Failed to generate sources. Aborting..." );
          return -1;
        }
    }

  if ( option == 4 )
    {
      if ( dup_source ( path, "Cpp_CMake_Project" ) )
        {
          printf ( "%s\n", "Failed to generate sources. Aborting..." );
          return -1;
        }
    }

  printf ( "\n%s\n", "Done. Happy coding!" );

  return 0;
}