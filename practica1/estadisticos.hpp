#ifndef __ESTADISTICOS_HPP__
#define __ESTADISTICOS_HPP__

#include <vector>

using std::vector;


double sumatorioVector(const vector<double> v){
	double sumatorio = 0;
	
	for(unsigned int i = 0; i < v.size(); i++)
		sumatorio += v[i];

	return sumatorio;
}


double varianza(const vector<double> &v){
	vector<double> vectorAux;
	double media = sumatorioVector(v)/v.size();

	for(unsigned int i = 0; i < v.size(); i++)
		vectorAux.push_back(pow(v[i] - media, 2));

	return sumatorioVector(vectorAux)/vectorAux.size();

}

double coeficienteDeterminacion(const vector<double> &vTiemposEstimados, const vector<double> &vTiemposObservados){
	return varianza(vTiemposEstimados)/varianza(vTiemposObservados);
}

#endif