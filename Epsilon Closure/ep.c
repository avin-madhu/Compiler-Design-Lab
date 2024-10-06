#include <stdio.h>

void dfs(int i, int n);
void reset_visited(int n);

int et[100][100]; // for storing epsilon transtions
int visited[100]; // wether a state is visited or not

int main()
{
  int number_of_states, number_of_transistions;
  printf("Enter the number of states: ");
  scanf("%d", &number_of_states);
  printf("Enter the number of transitions: ");
  scanf("%d", &number_of_transistions);

  // format i symbol j (use e for epsilon)
  printf("Enter the transitions: \n\n");
  int m,n;
  char symbol;
  
  // get the epsilon closure for each state
  for(int i=0;i<number_of_transistions;i++){
    scanf("%d %c %d",&m, &symbol, &n);
    if(symbol == 'e')
      et[m][n] = 1;
  }
  // finding the epsilon closure 
  for(int i=1; i<=number_of_states; i++){
    printf("\nEpsilon closure of state %d: ",i);
    reset_visited(number_of_states);
    dfs(i, number_of_states); printf("{ ");
    for(int j=1;j<=number_of_states;j++){
        if(visited[j]) 
            printf("%d ", j);
    } printf("}");
  }
  return 0;
}

void dfs(int v, int n) {
    visited[v] = 1;
    for(int i=1;i<=n;i++){
        if(et[v][i] == 1 && visited[i] == 0){
            dfs(i, n);
        }
    }
}

void reset_visited(int n) {
    for(int i=1;i<=n;i++){
        visited[i] = 0;
    }
}