#include <unistd.h>
#include <stdlib.h>

int main( int argc, char *argv[]) {
    // Taking argument values for the size ,  width and iterations
    size_t size = atoi(argv[ 1 ]);
    size_t width = atoi(argv[ 2 ]);


    printf("The size %d, widht %d\n", size,width);

    // Memory Data Allocation
    char* array = calloc(size*width, sizeof(char));

    //If Data was allocated execute the following
    if (array) {

        // Initializing data values.
        for (int i = 0;i<size;i++){
            for(int j =0;j<width;j++){
                // element[i].element[j]=i*j;
                array[i*width + j] =(char)(i+1)*(j+1);
                printf("The Element val: %d , at m:%d, n:%d\n", array[i*width + j],i,j);

            }
        }
        //Bitwise computation iterator

        //Iterating thorught the number of elements
        for (int i = 0;i<(size/2);i++){
            // Iterating thorugh word bitwise operation based on the width.
            //Example: width = 8, means that each element has two words and both
            //so we do array[0][0]&array[1][0], and array[0][1]&array[1][1]
            for(int j = 0; j<(width);j+=4){
                // Prionting the word parsed element
                printf("i:%d j:%d\n",i,j );
                printf("Offset%d\n",array[(i*2)*width+(j )]);
                printf("The first Val: %04x\n",((unsigned int* )( &array[(i*2)*width+(j )]))[0] );
                printf("The Second Val:%04x\n",((unsigned int* )( &array[((i*2+1)*width)+(j)] ))[0] );

                // Executing bitwise operation
                unsigned int val = ((unsigned int* )( &array[(i)*width+(j)]))[0] & ((unsigned int* )( &array[((i+1)*width)+(j)] ))[0];
                printf("The element:  %04x\n\n", val );
            }


        }
        printf("Total Operations:%d \n",size/2*(width/4));
        free(array); /* release the memory */
    }
    return 0;
}
