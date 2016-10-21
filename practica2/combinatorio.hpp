#ifndef __COMBINATORIO__
#define __COMBINATORIO__

struct stTabla{
	double n,k, resultado;
};

double combinatorioRecursivo(double N, double K){
	double resultado;
	if(K == 0 || K == N)
		resultado = 1;

	else
		resultado = combinatorioRecursivo(N-1, K-1) + combinatorioRecursivo(N-1, K);

	return resultado;
}

double combinatorioRecursivo(double N, double K, vector<stTabla> &v){
	stTabla aux;
	aux.n = N;
	aux.k = K;	
	
	bool encontrado = false;
	unsigned int i = 0;
	
	while(!encontrado && i<v.size()){
		if(v[i].n == N && v[i].k == K)
			encontrado = true;
		else i++;
	}

	if(encontrado)
		return v[i].resultado;		

	else{
		if(K==N || K==0){
			aux.resultado = 1;
			v.push_back(aux);
			return 1;
		}
		else{
			aux.resultado = combinatorioRecursivo(N-1,K-1, v) + combinatorioRecursivo(N-1,K, v);
			v.push_back(aux);
			return aux.resultado;
		}
	}
}

double factorial(int n){
  if(n < 2)
    return 1;
  else
    return n * factorial(n-1);
}

double combinatorioIterativo(double N, double K){
	return factorial(N) /(factorial(N-K) * factorial(K));
}

#endif