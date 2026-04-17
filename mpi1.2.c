#include <stdio.h>
#include <string.h>  
#include <mpi.h>     

int main(void) {
   int        comm_sz;               /* Número de processos    */
   int        my_rank;               /* Rank   do processo     */

   int a = 5;
   int b = 2;
   int res;
   int resComum;
   /* Inicia MPI */
   MPI_Init(NULL, NULL); 

   /* Obter número de processos */
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); 

   /* Obter rank (id) do processo */
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 

   if (my_rank == 0){
         res = a + b;
         int res1;
         int res2;
         MPI_Recv(&res1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
         MPI_Recv(&res2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
         resComum = res + res1 + res2;
   }
   else{
      if (my_rank == 1)
         res = a - b;
      if (my_rank == 2)
         res = a * b;
         
      MPI_Send(&res, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
   }
   
   MPI_Bcast(&resComum, 1, MPI_INT, 0, MPI_COMM_WORLD);
   int resFinal = resComum * res;
   printf("Resposta: %d (%d * %d), Processo: %d\n", resFinal, resComum, res,  my_rank);

   /* Encerra MPI */
   MPI_Finalize(); 

   return 0;
}  /* main */
