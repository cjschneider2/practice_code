int* int_tokenizer (char *line)
{
#define MAX_SIZE 1024
   int
      idx = 0, /* index value into array */
      *values = calloc (MAX_SIZE, sizeof(int)); /* our return list */
   char
      *token = strtok (line, " "); /* the space ' ' is our "splitting char" */

   while (token != NULL)
   {
      sscanf (token, "%d", (values + idx) ); /* some pointer math for the array pos */
      token = strtok (NULL, " ");
      idx++;
   }
   return values;
}
