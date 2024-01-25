#include "hist_pp.h"
void cucu_test(){

//TGraphErrors** result=hgpythia_ref();
//result[0]->Draw();
TH1D** dau_hist=hist_dau();
dau_hist[0]->Draw();

}
