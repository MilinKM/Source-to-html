#include "main.h"

/* start_or_end_conv function definitation */
void begin_html (FILE *dst_fp) 
{
	/* Add HTML begining tags into destination file */
	fprintf (dst_fp, "<!DOCTYPE html>\n");
	fprintf (dst_fp, "<html lang=\"en-US\">\n");
	fprintf (dst_fp, "<head>\n");
	fprintf (dst_fp, "<title>%s</title>\n", "code2html");
	fprintf (dst_fp, "<meta charset=\"UTF-8\">\n");
	fprintf (dst_fp, "<link rel=\"stylesheet\" href=\"styles.css\">\n");
	fprintf (dst_fp, "</head>\n");
	fprintf (dst_fp, "<body style=\"background-color:black; font-size:16px\">\n");
	fprintf (dst_fp, "<pre>\n");
}

void end_html (FILE *dst_fp) 
{
	/* Add HTML closing tags into destination file */
	fprintf (dst_fp, "</pre>\n");
	fprintf (dst_fp, "</body>\n");
	fprintf (dst_fp, "</html>\n");
}

void add_line_no (FILE *dst_fp, int line_no)
{
	/* code to enable line number */
	fprintf (dst_fp, "<span style=\"color:crimson\">%3d</span> ", line_no);

}

