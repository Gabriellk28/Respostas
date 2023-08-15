//TAD ContaBancaria
typedef struct contabancaria ContaBancaria;

//Função que cria uma conta
ContaBancaria *cria_conta(char *nome, int numero, float saldo);

//Função que deposita um saldo na conta
void deposita(ContaBancaria *cb, float valor);

//Função que saca o saldo de uma conta
void saca(ContaBancaria *cb, float valor);

//Função que transfere o saldo de uma conta
void transfere(ContaBancaria *cb1, ContaBancaria *cb2, float valor);

//Função que recebe retorna o saldo de uma conta
float saldo(ContaBancaria *cb);

//Função que exclui uma conta
void exclui_conta(ContaBancaria *cb);