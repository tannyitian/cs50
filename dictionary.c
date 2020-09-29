// Implements a dictionary's functionality

#include <stdbool.h>
#include <getopt.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>
#include <strings.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
// TODO
//  check - take a word and check if it is in the dictionary
// return true if word is in dictionary false otherwise
// case insensitive
// strcasecmp
// hash word to obtain hash value
// access linked list at that index in the hash table
// traverse linked list, looking for the word
// how to traverse? set up a variable to point to the first element, if not the one we are finding,
// set cursor to whatever next node of first element is pointing to, repeating until find word, true. Eventually end of the linked list which is NULL means we cant find the word.



    int ind = hash(word);
    node* new_node = table[ind];
    if (table[ind] != NULL)
    {
        while (new_node != NULL)
        {
            if (strcasecmp(new_node->word, word) == 0)
            {
                return true;
            }
            else
            {
                new_node = new_node->next;

            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO

    char check[strlen(word)];
    strcpy(check, word);
    char check_d = tolower(check[0]);
    int ind = check_d - 'a';

    return ind;

    // int hash = 0;
    // int n;
    // for (int i=0; word[i] != '\0'; i++)
    // {
    //     if (isalpha(word[i]))
    //         n = word[i] - 'a' + 1;
    //     else
    //         n=27;

    //     hash = ((hash << 3) + n) % N;
    // }

    // return hash;

}


bool loaded1 = false;
int number = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    char word[LENGTH+1]; //Length is defined in dictionary.h
    for (int i =0; i<N; i++)
        table[i] =  NULL;//

    FILE* inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        return 1;
    }

    while (fscanf(inptr, "%s", word) != EOF)
    {
        node* n = malloc(sizeof(node));
        if(n == NULL)
        {
            free(n); //
            return 1;
        }
        number++;
        strcpy(n->word, word); //copying word to node
        int index = hash(word);
        n->next = table[index]; //set new_node next pointer to the first element of the linked list
        table[index] = n; //set head pointer to point to new_node is pointing

    }

    fclose(inptr);
    loaded1 = true;
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    if (loaded1 == false)
    {
        return 1;
    }
    else
    {
        return number;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for(int i =0; i<N; i++)
    {

        if(table[i] != NULL)
        {
            node* cursor = table[i];
            while(cursor->next != NULL)
            {
                node* tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }

        }
    }

    // TODO

    return true;
}

