// aluno: thiago ramalho//
// não sei porque, mas a minha lista sumiu aq no github//
# inclui  < stdio.h >
# inclui  < stdlib.h >

int  main () {
    número int = 10 ; // Ponteiro, guarda o endereço de memória que contem um numero inteiro
    int * numeroP = & numero; // variavel que guarda um endenreço de memoria
    printf ( " Valor da variável número: % d \ n " , número); // valor guardado na variavel number
    printf ( " Endereço da variável número: % p \ n " , & número); // endereço de número
    printf ( " Valor da variável numberP: % p \ n " , numberP); // valor da variavel numberP
    printf ( " Valor apontado por numberP: % d \ n \ n " , * numberP); // valor guardado no endereço apontado por número P
    printf ( " Mudando o valor de número de forma indireta \ n \ n " );
    * número P = 15 ; // é a mesma coisa que number = 15;
    printf ( " Valor da variável número: % d \ n " , número);
    numberP ++; 
    printf ( " Valor da variável numberP: % p \ n " , numberP);
    printf ( " Valor no endereço apontado: % d \ n " , * númeroP);
    float * pi = ( float *) malloc ( sizeof ( float )); // malloc: aloca espaco para um bloco de bytes consecutivos na memoria ram e devolve o endereco inicial desse bloco
    printf ( " Valor da variável pi: % p \ n " , pi );
    * pi = 3,1415 ;
    printf ( " Valor no endereço apontado: % f \ n " , * pi );
    livre ( pi ); // libera o endereco de memoria que guardava a variavel pi guardava
    printf ( " Valor da variável pi: % p \ n " , pi );
    printf ( " Valor da variável apontada: % f \ n " , * pi );
    * pi = 0 ;
    pi = NULL ; // para nao deixar rastros na memoria
    int * números = ( int *) malloc ( sizeof ( int ) * 3 ); // alocado 3 vezes o tamanho de um int
    * (números + 0 ) = 1 ; // mesmo que números [0] = 1;
    * (números + 1 ) = 2 ; // mesmo que números [1] = 2;
    * (números + 2 ) = 3 ; // || || números [2] = 3;
 // formas para testar o preenchimento dos números variáveis   
    para ( int i = 0 ; i < 3 ; i ++)
        printf ( " números [ % d ] = % d \ n " , i, números [i]);
    
    para ( int i = 0 ; i < 3 ; i ++)
        printf ( " * (números + % d ) = % d \ n " , i, * (números + i));
    
    int * aux = números;
    para ( int i = 0 ; i < 3 ; i ++) {
        printf ( " aux = % d \ n " , * aux);
        aux ++;}
retornar EXIT_SUCCESS;}
