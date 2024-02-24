#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Number of dishes that fit on the table */
#define TABLE_SPACE 5

typedef struct {
    int dish; /* The identifier of the dish currently on this platter */
    int uses; /* The number of times a dwarf has requested the dish on this platter */ 
} platter;

/* The platters for serving the dishes during this feast */
platter* platters;

/* Gets the next dish order from the very hungry dwarves.
   Returns -1 if we have (finally) fed the dwarves all 
   they could eat (reached the end of input).
 */
int get_next_dish_order();

/* Prints to the console, in a (relatively) pretty format,
   the contents of the platters currently on the table. 
   Run this after each step of your algorithm to see what's
   going on on the table. Helps you visualize what is going
   on, even if dishes have numbers instead of names
 */
void print_state();

/*  Serve dishes to the dwarves based on their requests. The 
    replacement strategy is LEAST FREQUENTLY USED (LFU).
    This function returns an integer count of the number of 
    times Bilbo has had to fetch a dish to put on one of the platters.
    Remember to call print_state() after each time a dish request
    is dealt with! 
*/
int serve_dishes( ) {



}

int main( int argc, char** argv ) {

    /* Allocate and initialize platters */
    
    int fetches = serve_dishes(); 
    printf("Bilbo had to fetch dishes %d times using LFU.\n", fetches );
    
    /* Deallocate platters */
    
    return 0;
}


/****** Do not change anything below this line -- Internal Functionality Only ********/ 

int get_next_dish_order( ) {
    if ( feof(stdin) ) {
        return -1;
    }
    int next;
    scanf("%d", &next);
    return next;
}

void print_state( ) { 
    printf("("); 
    for ( int i = 0; i < TABLE_SPACE - 1; i++ ) { 
        if (platters[i].uses == -1) {
            printf("- [], ");
        } else {
            printf( "%d [%d], ", platters[i].dish, platters[i].uses );
        }
    }
    if ( platters[TABLE_SPACE - 1].uses == -1 ) {
        printf("- [])\n");
    } else {
        printf("%d [%d])\n", platters[TABLE_SPACE - 1].dish, platters[TABLE_SPACE -1].uses );
    }
}

