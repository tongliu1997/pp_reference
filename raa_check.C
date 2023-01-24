#include "hist_pp.h"

void raa_check(){
    TH1D** auau=hist_auau();
    TH1D* pp=hist_pp();
    TH1D** raa=hist_raa();

TCanvas* c1=new TCanvas();
c1->Divide(3,2);

    for(int i=0;i<6;i++){
	int i_aa=i?i+1:i;
        TH1D* aa=(TH1D*)auau[i_aa]->Clone();
	aa->Scale(1.4/aa_nbin[i_aa]);
	aa->Divide(pp);
	aa->SetLineColor(kRed);
	c1->cd(i+1);
//	raa[i]->Draw("same");
//	aa->Draw("same");
	aa->Divide(raa[i]);
	aa->DrawClone();
    }



}
