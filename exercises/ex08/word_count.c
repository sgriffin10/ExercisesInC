#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>


void print_iterator(gpointer item, gpointer postfix) {
 printf("%s %s", (char*)item, (char*)postfix);
}


void iterator(gpointer key, gpointer value, gpointer user_data) {
 printf(user_data, (char*)key, *(int*)value);
}


void free_data(gpointer data){
  memset(data,0,sizeof(*data));
  free(data);
}

GSList* get_word_list(char *line, GSList *list){
  const char delimiters[] = " .,;:\"\"!-?()\t\n'";
  char* token;
  token = strtok(line, delimiters); 
  list = g_slist_append(list, token); 
  while(token != NULL){
    token = strtok(NULL, delimiters);
    if(token != NULL){
      list = g_slist_append(list, token);
    }
  }
  return list;
}


void histogram(gpointer key, gpointer hash){
  GHashTable *hashtable = (GHashTable *)hash;
  char* new_key = (char*) key;
  char* old_key;
  int* old_value;
  int* new_value = calloc(1,sizeof(int));
  gboolean item_ptr = g_hash_table_lookup_extended(hashtable, new_key, (void**)&old_key, (void**)&old_value);
  if(item_ptr){
    *new_value = (*old_value) + 1;
    g_hash_table_remove(hashtable, new_key);
    g_hash_table_insert(hashtable, g_strdup(new_key), new_value);
  }
  else{
     *new_value = 1;
     g_hash_table_insert(hashtable, g_strdup(new_key), new_value);
  }
}

int main(int argc, char *argv[]){
  FILE *file;
  char *line = calloc(1024, sizeof(char));
  size_t len = 0;
  GHashTable *hash = g_hash_table_new_full(g_str_hash, g_str_equal, free_data,free_data);

  if (argc != 2) {
      fprintf(stderr, "Usage: %s <file>\n", argv[0]);
      exit(EXIT_FAILURE);
  }

  file = fopen(argv[1], "r");
  if (file == NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
  }

  while (getline(&line, &len, file) != -1) {
    if(line[0] < 65){ 
      continue;
    }
    GSList *wordslist = NULL;
    wordslist = get_word_list(line,wordslist);
    g_slist_foreach(wordslist, print_iterator," ");
    printf("The list is now %d items long\n", g_slist_length(wordslist));
    g_slist_foreach(wordslist, histogram,hash); 
    g_slist_free(wordslist);
  }
  g_hash_table_foreach(hash, (GHFunc)iterator, "%s: %d\n"); 
  free(line);
  g_hash_table_destroy(hash);
  fclose(file);
  exit(EXIT_SUCCESS);
  return 0;

}