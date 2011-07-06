
#include <cstdlib>
#include<iostream>
#include<ctime>
#include<stdio.h>
//see Cuda by examples book
//#include"book.h"

#define SIZE    (100*1024*1024)
#define ELEMENTS    (SIZE / sizeof(unsigned int))

#define HASH_ENTRIES 1024

using namespace std;



/* The hash table consist essentially of two parts:
 * 1) hash function
 * 2) data structure of buckets: array of length N,
 *    and each entry holds a list of key-value pairs
 */

/*Structure to holds a key and value*/
struct Entry {        
    unsigned int key; //store our key-value pairs
    void* value;      //left void* to store any data
    Entry *next;      //After collisions, w'll have multiple entries in the same
                      //bucket, so we store these entries as a list
};


/*Structure to hold the Table = array of buckets*/
struct Table {
    size_t count;    //array length
    Entry **entries; // pointer to array
    Entry *pool;     //large array of available entries in pool
    Entry *firstFree; //Next available entry for use
};


/*Support and helper functions*/
void initialize_table (Table &table, int entries, int elements) {
    table.count = entries;
    table.entries = (Entry**)calloc(entries, sizeof(Entry*));
    table.pool = (Entry*)calloc(elements, elements * sizeof (Entry));
    table.firstFree = table.pool;
}

void free_table(Table& table) {
    free(table.entries);
    free(table.pool);
}

void* big_random_block( int size ) {
    unsigned char *data = (unsigned char*)malloc( size );
    //HANDLE_NULL( data );
    for (int i=0; i<size; i++)
        data[i] = rand();

    return data;
}

//------------------------------------------------------------------------------

/*Here the hash function*/
size_t hash(unsigned int key, size_t count) {
    return key % count;
}


void add_to_table(Table &table, unsigned int key, void* value) {

    //Step 1: compute the hash funtion on the input
    size_t hashValue = hash(key, table.count);

    //Step 2: take preallocated Entry from the pool
    //and initialiaze it's key and value field

    Entry * location = table.firstFree++;
    location->key = key;
    location->value = value;

    //Step 3: insert the entry at the front of the proper bucket's list

    location->next = table.entries[hashValue];
    table.entries[hashValue] = location;
}

void verify_table( const Table &table ) {

    int count = 0;
    for (size_t i = 0; i < table.count; i++) {
        Entry    *current = table.entries[i];
         while (current != NULL) {
             ++count;
             if ( hash(current->value, table.count) != i)

             cout<<current->value<<" hashed to"<<hash(current->value, table.count)<<", but was located at"<<i<<endl;

             current = current->next;
        }
    }
    if (count != ELEMENTS)
        cout <<count<<" elements found in hash table. Should be "<<ELEMENTS<<endl;

    else
        cout <<"All "<<count<<" elements found in hash table"<<endl;

}


int main(int argc, char** argv) {

    unsigned int *buffer = (unsigned int*)big_random_block( SIZE );
    clock_t start, stop;
    start = clock();
    Table table;
    initialize_table( table, HASH_ENTRIES, ELEMENTS );
    for (int i=0; i<ELEMENTS; i++) {
        add_to_table( table, buffer[i], (void*)NULL );
    }
    stop = clock();
    float elapsedTime = (float)(stop - start) / (float)CLOCKS_PER_SEC * 1000.0f;
    
    printf( "Time to hash: %3.1f ms\n", elapsedTime );
    verify_table( table );
    free_table( table );
    free( buffer );



    return 0;
}

