# include "locator_pars.H"
# include <argp.h>
# include <stdlib.h>
# include "aleph.H"
# include "ahDaemonize.H"

const int Default_Cache_Out_Size = 101;

const int Default_Cache_In_Size = 101;

const int Default_Cache_Migration_Size = 101;

const int Default_Cache_Garbage_Size = 101;

const int Default_Cache_New_Bindings_Size = 101;

const int Default_Implicit_Message_Cnt_Size = 101;

const int Default_Object_Table_Size = 101;

const int Default_Container_Table_Size = 101;

const int Default_Wait_Response_Table_Size = 101;

const int Default_Wait_Broadcast_Resp_Table_Size = 101;

const int Default_MTU_Size = 2048;

const int Default_Implicit_Msgs_Per_Chunk = 10;

const int Default_Implicit_Msg_Dead_Age = 10;

const bool Default_Chunk_Size_Depends_On_MTU = false;

const bool Default_Attach_To_Broadcast_Group = false;

const char * Default_Local_Services_File_Path = "/tmp/.locatorPath";

const char * Default_Broadcast_Port_Path = "/home/Aleph/src/groups/.broadcast_port";

int cache_out_size;

int cache_in_size;

int cache_migration_size;

int cache_garbage_size;

int cache_new_bindings_size;

int implicit_message_cnt_size;

int object_table_size;

int container_table_size;

int wait_response_table_size;

int wait_broadcast_resp_table_size;

int mtu_size;

int implicit_msgs_per_chunk;

int implicit_msg_dead_age;

bool chunk_size_depends_on_mtu;

bool attach_to_broadcast_group;

static const char hello_preamble [] =
"\n"
"  ALEPH LOCATOR system\n"
"  Copyright (c) 2000, 2001\n"
"      University of Los Andes (ULA) Merida - VENEZUELA\n"
" - Center of Studies in Microelectronics & Distributed Systems (CEMISID)\n"
" - National Center of Scientific Computing of ULA (CECALCULA)\n"
"  All rights reserved."
"\n"
"\n"
;


static const char license_text [] =
"\n"
"Aleph Locator System License & Copyright Note\n"
"\n"
"  Copyright (c) 2000, 2001\n"
"  UNIVERSIDAD DE LOS ANDES (ULA) Merida - VENEZUELA\n"
"  All rights reserved.\n\n"

"  - Center of Studies in Microelectronics & Distributed Systems (CEMISID)\n"
"  - National Center of Scientific Computing (CECALCULA)\n\n"

"  PERMISSION TO USE, COPY, MODIFY AND DISTRIBUTE THIS SOFTWARE AND ITS \n"
"  DOCUMENTATION IS HEREBY GRANTED, PROVIDED THAT BOTH THE COPYRIGHT \n"
"  NOTICE AND THIS PERMISSION NOTICE APPEAR IN ALL COPIES OF THE \n"
"  SOFTWARE, DERIVATIVE WORKS OR MODIFIED VERSIONS, AND ANY PORTIONS \n"
"  THEREOF, AND THAT BOTH NOTICES APPEAR IN SUPPORTING DOCUMENTATION. \n"
"\n"
"  Aleph IPC system is distributed in the hope that it will be useful,\n"
"  but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. \n"
"\n"
"  UNIVERSIDAD DE LOS ANDES requests users of this software to return to \n"
"\n"
"      CEMISID - Software \n"
"      Ed La Hechicera \n"
"      3er piso, ala Este \n"
"      Facultad de Ingenieria \n"
"      Universidad de Los Andes \n"
"      Merida 5101 - VENEZUELA \n"
"\n"
"  or to 	software@cemisid.ing.ula.ve \n"
"\n"
"  any improvements or extensions that they make and grant Universidad \n"
"  de Los Andes (ULA) the full rights to redistribute these changes. \n"
"\n"
"Aleph IPC system is (or was) granted by: \n"
"- Consejo de Desarrollo Cientifico, Humanistico, Tecnico de la ULA  (CDCHT)\n"
"- Consejo Nacional de Investigaciones Cientificas y Tecnologicas (CONICIT)\n"
"\n"
"\n";

static char doc[] = "    Options are as follow:";

static char arg_doc[] = "";

struct Parameters
{
  int cache_out_size;
  
  int cache_in_size;
  
  int cache_migration_size;
  
  int cache_garbage_size;

  int cache_new_bindings_size;
  
  int implicit_message_cnt_size;
  
  int object_table_size;
  
  int container_table_size;
  
  int wait_response_table_size;
  
  int wait_broadcast_resp_table_size;
  
  int mtu_size;
  
  int implicit_msgs_per_chunk;
  
  int implicit_msg_dead_age;
  
  bool chunk_size_depends_on_mtu;
  
  bool attach_to_broadcast_group;

  bool null_output;

  bool daemonize;

  Parameters() :
    cache_out_size(Default_Cache_Out_Size),
    cache_in_size(Default_Cache_In_Size),
    cache_migration_size(Default_Cache_Migration_Size),
    cache_garbage_size(Default_Cache_Garbage_Size),
    cache_new_bindings_size(Default_Cache_New_Bindings_Size),
    implicit_message_cnt_size(Default_Implicit_Message_Cnt_Size),
    object_table_size(Default_Object_Table_Size),
    container_table_size(Default_Container_Table_Size),
    wait_response_table_size(Default_Wait_Response_Table_Size),
    wait_broadcast_resp_table_size(Default_Wait_Broadcast_Resp_Table_Size),
    mtu_size(Default_MTU_Size),
    implicit_msgs_per_chunk(Default_Implicit_Msgs_Per_Chunk),
    implicit_msg_dead_age(Default_Implicit_Msg_Dead_Age),
    chunk_size_depends_on_mtu(Default_Chunk_Size_Depends_On_MTU),
    attach_to_broadcast_group(Default_Attach_To_Broadcast_Group),
    null_output(false),
    daemonize(false)
  {
    // empty
  }
    
};



static struct argp_option options [] = 
{
  {"cache-out", 'o', 0, OPTION_ARG_OPTIONAL, "Set cache_out size", 0},
  {"cache-in", 'i', 0, OPTION_ARG_OPTIONAL, "Set cache_in size", 0},
  {"cache-mig", 'm', 0, OPTION_ARG_OPTIONAL, "Set cache_migration size", 0},
  {"cache-garbage", 'd', 0, OPTION_ARG_OPTIONAL, "Set cache_garbage size", 0},
  {"cache-new-bnds", 'w', 0, OPTION_ARG_OPTIONAL, "Set cache_new_bindings size", 0},
  {"imp-cnt-size", 'c', 0, OPTION_ARG_OPTIONAL, "Set implicit messages container size", 0},
  {"obj-table", 'b', 0, OPTION_ARG_OPTIONAL, "Set objects table size", 0},
  {"cnt-table", 'n', 0, OPTION_ARG_OPTIONAL, "Set containers table size", 0},
  {"resp-table", 'r', 0, OPTION_ARG_OPTIONAL, "Set waiting response table size", 0},
  {"broadcast-table", 'l', 0, OPTION_ARG_OPTIONAL, "Set broadcast response table size", 0},
  {"mtu", 't', 0, OPTION_ARG_OPTIONAL, "Set Maximum Transfer Unit (MTU) size in bytes", 0},
  {"imp-per-chunk", 'p', 0, OPTION_ARG_OPTIONAL, "Set number of imlpicit messages per chunk", 0},
  {"dead-age", 'a', 0, OPTION_ARG_OPTIONAL, "Set implicit message dead age", 0},
  {"mtu-depend", 'e', 0, OPTION_ARG_OPTIONAL, "Set chunk dependance on mtu size", 0},
  {"daemonize", 'D', 0, OPTION_ARG_OPTIONAL, "Load locator as a daemon", 0},
  {"attach-group", 'G', 0, OPTION_ARG_OPTIONAL, "Attach locator to a group of locators", 0},
  {"null-desc", 'u', 0, OPTION_ARG_OPTIONAL, "Load locator with stdin, stdout and stderr as null file descriptors", 0},
  
  { 0 }
};

void process_size(int & size_var, 
		  const char * size_name, 
		  const char opt_char, 
		  struct argp_state *state)
{
  if (state->argv[state->next] == NULL)
    EXIT("missing %s size in -%c option\n", size_name, opt_char);
  
  char *end;
  
  size_var = strtol(state->argv[state->next], &end, 10);
  
  if (*end != '\0' && *end != '\n')
    EXIT("Bad format in -%c %s option\n", opt_char, state->argv[state->next]);
  if (size_var < 0)
    EXIT("%s size can't be negative value.\n", size_name);
  state->next++;
}


static error_t parser_opt(int key, char *arg, struct argp_state *state)
{
  Parameters *pars_ptr = static_cast<Parameters*>(state->input);

  switch (key)
    {
    case ARGP_KEY_END:
      break;
    case 'o':
      {
	process_size(pars_ptr->cache_out_size, "cache-out", 'o', state);
	break;
      }
    case 'i':
      {
	process_size(pars_ptr->cache_in_size, "cache-in", 'i', state);
	break;
      }
    case 'm':
      {
	process_size(pars_ptr->cache_migration_size, 
		     "cache-migration", 'm', state);
	break;
      }
    case 'd':
      {
	process_size(pars_ptr->cache_garbage_size, 
		     "cache-garbage", 'd', state);
	break;
      }
    case 'w':
      {
	process_size(pars_ptr->cache_new_bindings_size, 
		     "cache-new-bindings", 'w', state);
	break;
      }
    case 'c':
      {
	process_size(pars_ptr->implicit_message_cnt_size, 
		     "implicit-msgs-container", 'c', state);
	break;
      }
    case 'b':
      {
	process_size(pars_ptr->object_table_size, "objects-table", 'b', state);
	break;
      }
    case 'n':
      {
	process_size(pars_ptr->container_table_size, 
		     "container-table", 'n', state);
	break;
      }
    case 'r':
      {
	process_size(pars_ptr->wait_response_table_size, 
		     "wait-response-table", 'r', state);
	break;
      }
    case 'l':
      {
	process_size(pars_ptr->wait_broadcast_resp_table_size, 
		     "wait-broadcast-response-table", 'l', state);
	break;
      }
    case 't':
      {
	process_size(pars_ptr->mtu_size, "MTU", 't', state);
	break;
      }
    case 'p':
      {
	process_size(pars_ptr->implicit_msgs_per_chunk, 
		     "implicit-msgs-per-chunk", 'p', state);
	break;
      }
    case 'a':
      {
	process_size(pars_ptr->implicit_msg_dead_age, 
		     "implicit-msg-dead-age", 'a', state);
	break;
      }
    case 'e':
      {
	pars_ptr->chunk_size_depends_on_mtu = true;
	break;
      }
    case 'G':
      {
	pars_ptr->attach_to_broadcast_group = true;
	break;
      }
    case 'u':
      {
	pars_ptr->null_output = true;
	break;
      }
    case 'D':
      {
	pars_ptr->daemonize = true;
	pars_ptr->null_output = true;
	break;
      }
    case ARGP_KEY_ARG:
    default: return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

static struct argp arg_defs = { options, parser_opt, arg_doc, doc };

void parameters_decode(int argc, char * argv[])
{
  Parameters pars;
  
  error_t status = argp_parse(&arg_defs, argc, argv, 0, 0, &pars);
  
  if (status != 0)
    EXIT("Internal error in parsing of commands line: %s", strerror(errno));

  cache_out_size = pars.cache_out_size;
  
  cache_in_size = pars.cache_in_size;
  
  cache_migration_size = pars.cache_migration_size;
  
  cache_garbage_size = pars.cache_garbage_size;
  
  cache_new_bindings_size = pars.cache_garbage_size;
  
  implicit_message_cnt_size = pars.implicit_message_cnt_size;
  
  object_table_size = pars.object_table_size;
  
  container_table_size = pars.container_table_size;
  
  wait_response_table_size = pars.wait_response_table_size;

  wait_broadcast_resp_table_size = pars.wait_broadcast_resp_table_size;
  
  mtu_size = pars.mtu_size;
  
  implicit_msgs_per_chunk = pars.implicit_msgs_per_chunk;
  
  implicit_msg_dead_age = pars.implicit_msg_dead_age;
  
  chunk_size_depends_on_mtu = pars.chunk_size_depends_on_mtu;

  attach_to_broadcast_group = pars.attach_to_broadcast_group;

  if (pars.daemonize)
    {
      stdout = stderr = stdin = fopen("/dev/null", "r+");
      if (stdout == NULL)
	EXIT("%s\n", strerror(errno));
      
      daemonize(argv[0], LOG_USER);
    }

  if (pars.null_output)
    {
      stdout = stderr = stdin = fopen("/dev/null", "r+");
      if (stdout == NULL)
	EXIT("%s\n", strerror(errno));
    }
}
