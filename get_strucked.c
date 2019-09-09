#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct structa {
	char 		c; 	//1 -- 1
	char 		p;	//2 -- 2
	short int 	s; 	//2 -- 4 
	int 		i; 	//4 -- 8
	double 		d; 	//8 -- 16
}struct_t; 		// 16

//structure a
typedef struct structa_tag 
{ 
   char        c; 	//1 -- 2 (1 - padding)
   short int   s; 	//2 -- 4
} structa_t; 		// 4
  
//structure b
typedef struct structb_tag 
{ 
   short int   s; 	//2 -- 2
   char        c; 	//3 -- 4 (1 - padding)
   int         i; 	//4 -- 8
} structb_t; 		//8

/* structure C and structure D has same datatype and exact same number of variable
 * but we see:
 * sizeof(structure C) = 24
 * sizeof(structure D) = 16
 * Why ? structure D has minimised structure padding by defining variables in decreasing 
 * size of their datatype. Whereas in structure C, char is leading to max padding.
 * Why we have added 4byte extra at the end of structure C. Because the compiler does the 
 * padding in such a way that it is a multipe of largest datatype of that structure
 */

// structure C

typedef struct structc_tag 
{ 
   char        c; 	//1 -- 8 (7 - padding)
   double      d; 	//8 -- 16
   int         s; 	//4 -- 20
} structc_t; 		//24 //20 not multiple of 8 (largest in struct)
  
// structure D 
typedef struct structd_tag 
{ 
   double      d; 	//8 -- 8
   int         s; 	//4 -- 12
   char        c; 	//1 -- 14 (1 - padding)
} structd_t; 		//16

typedef struct book {
	char 		*a; //8
	char 		*b;	//16
	int 		*c;	//24
	float 		*d;	//32
}my_data_t;


/* What if you dont want the compiler to add padding to your structures
 * You tell the compiler when you declear the structure
 * either by 
 *		#pragma pack(1) 				Make all structure under it packed
 *		__attribute__((packed))			Make the structure defined packed
 */

//copy of structure c
typedef struct __attribute__((packed))structc_tag_copy
{
	char		c;
	double		d;
	int			s;
}structccopy_t;


int main(int argc, char const *argv[])
{
	printf("structure 1: %lu\n", sizeof(struct_t));
	printf("structure a: %lu\n", sizeof(structa_t));
	printf("structure b: %lu\n", sizeof(structb_t));
	printf("structure c: %lu\n", sizeof(structc_t));
	printf("structure d: %lu\n", sizeof(structd_t));
	printf("structure pointers: %lu\n", sizeof(my_data_t));
	printf("structure structccopy_t: %lu\n", sizeof(structccopy_t));
	return 0;
}