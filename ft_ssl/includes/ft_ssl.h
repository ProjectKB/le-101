#ifndef FT_SSL_H

# define FT_SSL_H

# include "libft.h"
# include "md5.h"
# include "sha256.h"
# include "base64.h"
# include "des.h" 
# include <fcntl.h>
# include <readpassphrase.h>

# define FILE 0
# define STDOUT 1
# define STDIN 2
# define STRING 3
# define QUIET 4
# define REVERSE 5

# define FALSE 0
# define TRUE 1

# define MD5 0
# define SHA256 1
# define BASE64 2
# define DES_ECB 3
# define DES_CBC 4

/*
** FLAGS
*/
# define FLAG_Q 0x1
# define FLAG_R 0x2
# define FLAG_P 0x4
# define FLAG_A 0x8
# define FLAG_F 0x10
# define FLAG_D 0x20
# define FLAG_O 0x40
# define FLAG_PP 0x80
# define FLAG_I 0x100
# define FLAG_AA 0x200
# define FLAG_K 0x400
# define FLAG_S 0x800
# define FLAG_V 0x1000
# define FLAG_PPP 0x2000
# define FLAG_AF 0x18
# define FLAG_AP 0xC
# define FLAG_QP 0x5
# define FLAG_AI 0x108
# define FLAG_PPPD 0x2020

/*
** ACTION
*/
# define DES 0x1
# define B64 0x2
# define PRINT 0x4
# define CHANGE_MOD 0x8
# define FREE_B64 0x10
# define FREE_PASS 0x20

/*
** STRUCT
*/
typedef struct		s_p
{
	int c;
	char **v;
}
					t_p;
					
typedef struct		s_hash
{
	t_md5			md5;
	t_sha256		sha256;
	t_base64		base64;
	t_des			des;
	t_p				args;
	unsigned char   line[65];
	unsigned char	*arg;
	unsigned int	flag;
	unsigned char	i;
	unsigned char	name[7];
	unsigned char	nb_bytes;
	unsigned char	action;
	int				rest;
	int				fd;
}					t_hash;

/*
** CONSTANT
*/
extern const char	*g_hash_name[5];

/*
** ARRAY OF FUNCTION POINTERS
*/
extern void 		(*g_pre_process_functions[5])(t_hash *h, int *i);
extern void			(*g_init_functions[5])(t_hash *h);
extern void			(*g_proceed_block_functions[5])(t_hash *h);
extern void			(*g_proceed_last_block_functions[5])(t_hash *h);
extern void			(*g_print_functions[5])(t_hash *h, int mod);
extern void			(*g_usage_functions[5])(t_hash *h);
extern void			(*g_free_functions[5])(t_hash *h);
extern void			(*g_flags_action[6])(t_hash *h, int *i);

/*
** MATERIALS FOR ARRAY OF FUNCTION POINTERS
*/
void				message_digest(t_hash *h, int *i);
void				base64(t_hash *h, int *i);
void				cipher_block(t_hash *h, int *i);

void				init_md5(t_hash *h);
void				init_decode_base64(t_hash *h);
void				init_encode_base64(t_hash *h);
void				init_base64(t_hash *h);
void				init_sha256(t_hash *h);
void				init_des(t_hash *h);

void				proceed_block_md5(t_hash *h);
void				proceed_block_sha256(t_hash *h);
void				decode_block_base64(t_hash *h);
void				encode_block_base64(t_hash *h);
void				proceed_block_base64(t_hash *h);
void    			proceed_block_des(t_hash *h);

void				proceed_last_block_md5(t_hash *h);
void				proceed_last_block_sha256(t_hash *h);
void				decode_last_block_base64(t_hash *h);
void				encode_last_block_base64(t_hash *h);
void				proceed_last_block_base64(t_hash *h);
void				proceed_last_block_des(t_hash *h);

void				print_md5(t_hash *h, int mod);
void				print_sha256(t_hash *h, int mod);
void				print_base64(t_hash *h, int mod);
void				print_des(t_hash *h, int mod);

void				usage_message_digest(t_hash *h);
void				usage_base64(t_hash *h);
void				usage_des(t_hash *h);

void    			k_des_flag(t_hash *h, int *i);
void    			s_des_flag(t_hash *h, int *i);
void    			v_des_flag(t_hash *h, int *i);
void    			p_des_flag(t_hash *h, int *i);
void    			i_des_flag(t_hash *h, int *i);
void    			o_des_flag(t_hash *h, int *i);

void				free_md5(t_hash *h);
void				free_sha256(t_hash *h);
void				free_base64(t_hash *h);
void				free_des(t_hash *h);


/*
** ERRORS
*/
void				bad_arg(char *bad_arg);
void				illegal_flag(void *flag, t_hash *h);
void				missing_arg(t_hash *h, char flag);
int					no_such_file(t_hash *h);


/*
** TOOLS
*/
void				init_hash(t_hash *h, int argc, char **argv);
int					get_fd(void *arg, int mod);
int					is_illegal_flag(unsigned char *arg);
void				set_bit(unsigned int *flag, int set, int unset);
void				set_bit2(unsigned char *flag, int set, int unset);
int					test_bit(unsigned int *flag, int flag_value);
int					test_bit2(unsigned char *flag, int flag_value);
void				print_and_quit(char *str, int fd);
void				EVP_bytes_to_Key(t_hash *h);
void				md5_hexa_custom(t_hash *h, int len);
void				base64_custom(t_hash *h, int flag);
void				base64_hexa_custom(t_hash *h, int len);
void 				generate_key(t_hash *h);
void				print_salt_key_iv(t_hash *h);
unsigned char		*ustrjoin(unsigned char const *s1, unsigned char const *s2);
unsigned char		*ustrjoin2(t_hash *h, unsigned char const *s1);
void				initial_check(t_hash *h);
void				freexit(t_hash *h, char *error, int fd);

/*
** SHARED
*/
int					define_algo(char *algo_name);
int					process(t_hash *h, int mod);
void				custom_print(t_hash *h, int mod, int turn);
void				print_hash(t_hash *h, int mod, char *stdin);

#endif
