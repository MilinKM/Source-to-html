#include "main.h"

/* definations */
char *reserved_key1[] = {"const", "volatile", "extern", "auto", "register", "static", "signed", "unsigned", "short", "long", "double", "char", "int", "float", "struct", "union", "enum", "void", "typedef", "FILE"};
char *reserved_key2[] = {"goto", "return", "continue", "break", "if", "else", "for", "while", "do", "switch", "case", "default", "sizeof", "EOF", "stderr", "stdout", "stdin"};
State_e Prev_state;

/* main part of the code */
int main (int argc, char *argv[])
{
	/* local variable declaration */
	FILE *src_fp, *dst_fp;
	char line_number[6] = "-n";
	src_fp = fopen(argv[1], "r");
	dst_fp = fopen(argv[2],"w+");
	/* checking command line arguments */
	if (argc == 1 || argc > 4 || argc < 3)
	{
		printf ("ERROR: ./<exe_file> <src_file.c> <output.html> <-n>\n");
		return FAILURE;
	}

	if (strcmp(argv[3], line_number))
	{
		if (argv[3] != '\0')
		{
		printf ("ERROR in 3: ./<exe_file> <src_file.c> <output.html> <-n>\n");
		return FAILURE;
		}
	}
    if (NULL == src_fp || NULL == dst_fp)
	{
	printf("invalid  file\n");
	return FAILURE;
	} 
	/*----------------------------------- --------main functional part -------------------------------------------------------------*/
	
	/* begin html function, that adds basic html tags */
	begin_html (dst_fp);

	/* the main function src_to_html, that converts source code to html color format */
	if (src_html(src_fp, dst_fp, argv[3]) == FAILURE)
	{
		printf ("Done: SUCCESSSSSSSSSSSSSS\n");
	}
	else
	{
		printf ("Done: FAILURE\n");
	}

	/* end html function, that adds basic html end tags */
	end_html (dst_fp);

	fclose (src_fp);
	fclose (dst_fp);

	return SUCCESS;
}
