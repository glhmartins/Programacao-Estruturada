// Aluno: Guilherme Martins Rangel

#include "fila1.c"

int main(){
    Aluno arr[] = {
        { "Ana", {8,7,0,0}, 1234567},
        { "Bia", {8,10,0,0}, 1234568},
        { "Edu", {9,8,0,0}, 1234569}
    };
    qCreate(); // Processo de criação/abertura da fila
    Logico size = sizeof(arr)/sizeof(Aluno); // Variavel que recebe o tamanho da lista
    for (int i=0; i<size; i++){ // For que vai do 0 ao tamanho da lista
        printf("tento colocar %s\n", arr[i].nome); // Printando o nome dos alunos que estão sendo colocados na fila
        if (qIn(arr[i]) == FALSE) printf("fila esta cheia!\n");
    }
    while(qIsEmpty() == FALSE){ // While que executara enquanto existir elementos na fila 
        Aluno aux;
        qOut(&aux);
        printf("saiu %s\n", aux.nome);
    }
    qDestroy(); // Processo de destruição/encerramento da fila
    return 0;
}