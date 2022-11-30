//definir um tipo conta (ponteiro para a conta)
typedef struct conta * p_conta;

//inicilizar um vetor do tamanho x de ponteiros para conta
void inicializar(p_conta pConta[], int tamanho);

// Deve inserir um registro de uma nova conta em uma posição do vetor de ponteiros.
void inserir(p_conta pConta[], int tamanho);

// Recebe um código de uma conta digitada pelo usuário e encontranda,
// solicita os novos dados para alteração. Pode-se alterar apenas o nome do cliente.
void alterar(p_conta pConta[], int tamanho);

// Recebe um código de uma conta digitada pelo usuário e localiza a conta no vetor,
// caso o encontre, é apresentado no console.
void procurar(p_conta pConta[], int tamanho);

// Imprime no console todos os dados de todas as contas correntes cadastradas no vetor.
void listar(p_conta pConta[], int tamanho);

// Recebe um valor positivo e efetua o depósito na conta informada, alterando o saldo da conta.
void depositar(p_conta pConta[], int tamanho);

// Recebe um valor positivo e efetua o saque na conta informada, alterando o saldo da conta.
void sacar(p_conta pConta[], int tamanho);

// Localiza uma conta e imprime os dados desta conta se existir.
void imprimir(p_conta pConta[], int tamanho);

// Mostra o saldo total de todas as contas cadastradas.
void saldoGeral(p_conta pConta[], int tamanho);