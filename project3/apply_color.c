#include "main.h"
/* function to apply HTML color scheme */
void apply_color (FILE *dst_fp, char *data, State_e state)
{
	/* check for < and > symbol, if present replace with &lt; and &gt; resp */

	memset (temp_buff, '\0', sizeof (temp_buff));
	replace_html_symbol (data);

	/* code to apply HTML tags and color scheme on source string */
	switch (state)
	{
		case s0_idle:
			fprintf (dst_fp, "<span class=\"idle\">%s</span>", temp_buff);
			break;

		case  s1_comment:
			fprintf (dst_fp, "<span class=\"comment\">%s</span>", temp_buff);
			break;

		case  s2_preprocessor:
			fprintf (dst_fp, "<span class=\"preprocess_dir\">%s</span>", temp_buff);
			break;

		case  s3_headerfile:
			fprintf (dst_fp, "<span class=\"header_file\">%s</span>", temp_buff);
			break;

		case  s4_res_keyword_data:
			fprintf (dst_fp, "<span class=\"reserved_key1\">%s</span>", temp_buff);
			break;

		case  s5_res_keyword_non_data:
			fprintf (dst_fp, "<span class=\"reserved_key2\">%s</span>", temp_buff);
			break;

		case  s6_string:
			fprintf (dst_fp, "<span class=\"string\">%s</span>", temp_buff);
			break;

		case  s7_numeric_constant:
			fprintf (dst_fp, "<span class=\"numeric_constant\">%s</span>", temp_buff);
			break;

		case  s8_ASCII_char:
			fprintf (dst_fp, "<span class=\"ascii_char\">%s</span>", temp_buff);
			break;
	}
}
void replace_html_symbol (char *dat)
{
	int index = 0, jndex = 0;
	while(dat [jndex])
	{
		if (dat [jndex] == '<')
		{
			temp_buff [index++] = '&'; 
			temp_buff [index++] = 'l'; 
			temp_buff [index++] = 't'; 
			temp_buff [index++] = ';'; 
		}
		else if (dat [jndex] == '>')
		{
			temp_buff [index++] = '&'; 
			temp_buff [index++] = 'g'; 
			temp_buff [index++] = 't'; 
			temp_buff [index++] = ';'; 
		}
		else
		{
			temp_buff [index++] = dat [jndex]; 
		}
		jndex++;
	}
	temp_buff [index] = '\0';

}

