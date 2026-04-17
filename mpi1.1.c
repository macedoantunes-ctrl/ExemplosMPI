#include <stdio.h>
#include <string.h>  
#include <mpi.h>     

int main(void) {
   int        comm_sz;               /* Número de processos    */
   int        my_rank;               /* Rank   do processo     */

   int a = 5;
   int b = 2;
   int res;

   /* Inicia MPI */
   MPI_Init(NULL, NULL); 

   /* Obter número de processos */
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); 

   /* Obter rank (id) do processo */
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 

   if (my_rank == 0)
      res = a + b;
   if (my_rank == 1)
      res = a - b;
   if (my_rank == 2)
      res = a * b;
   printf("Número de processos: %d Rank do processos corrente: %d \n", comm_sz, my_rank);
   printf("Resposta: %d\n", res);

   /* Encerra MPI */
   MPI_Finalize(); 

   return 0;
}  /* main */
