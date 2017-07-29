#ifndef MAIN_H
#define MAIN_H

/* Header include */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* user defined macros */
#define FAILURE -1
#define SUCCESS 0
#define SET 1
#define RESET 0

/* global Declarations */
char line_no, headerfile_flag;
char string_buff [100], temp_buff[100];
char buffer [2048];
char start_string;

/* user defined enums for States */
typedef enum States
{
	s0_idle,
	s1_comment,
	s2_preprocessor,
	s3_headerfile,
	s4_res_keyword_data,
	s5_res_keyword_non_data,
	s6_string,
	s7_numeric_constant,
	s8_ASCII_char
}State_e;

/* user defined enums for Events */
typedef enum Events
{
	PEVENT_NULL,
	PEVENT_SINGLE_LINE_COMMENT,
	PEVENT_MULTI_LINE_COMMENT,
	PEVENT_PREPROCESSOR_DIRECTIVE,
	PEVENT_HEADERFILE,
	PEVENT_RESERVED_KEYWORD,
	PEVENT_STRING,
	PEVENT_NUMERIC_CONSTANT,
	PEVENT_ASCII_CHAR,
	PEVENT_EOF
}Event_e;

/* user defined enums for colors */
typedef enum Colors
{
	black,
	blue,
	purple,
	green,
	yellow,
	orange,
	magenta,
	red
}color_e;

/* user defined function prototype */
void apply_color (FILE *dst_fp, char *data, State_e state);
int src_to_html (FILE *src_fd, FILE *dst_fp, char *line);
/*int get_words (char *buff);
Event_e get_event (char *buff, State_e state, Event_e event);
State_e get_state (char *string, State_e state);
void add_line_no (FILE *dst_fp, int line_no);
State_e check_for_reserved_key (char *string);
State_e check_numeric_const (char *string); */
void replace_html_symbol (char *dat);
void begin_html(FILE *dst_fp);
void end_html(FILE *dst_fp);

#endif
