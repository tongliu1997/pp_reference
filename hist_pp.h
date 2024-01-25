#include "/home/tl543/embed_isobar_tree/embed_species.h"
TH1D* hist_pp(bool include_err=true){
const char* filename="/home/tl543/pp_reference/HEPData-ins619063-v1-Table_1.root";
  TFile* file=new TFile(filename);
  TDirectoryFile* table=(TDirectoryFile*)file->Get("Table 1");

  TH1D* hist_pp_ref=(TH1D*)table->Get("Hist1D_y9");
  TH1D* err_pp_ref=(TH1D*)table->Get("Hist1D_y9_e1");

  TH1D* result=new TH1D("pp_spectrum","pp spectrum",nbins,xbins);

  for(int i=1;i<=hist_pp_ref->GetNbinsX();i++){
    double value=hist_pp_ref->GetBinContent(i);
    double err=(include_err)?err_pp_ref->GetBinContent(i):0;

    result->SetBinContent(i+3,value);
    result->SetBinError(i+3,err);
  }
  
  return result;

}


int aa_bins[8]={0,5,10,20,30,40,60,80};
double aa_nbin[7]={1051.3,-1,591.3,368.6,220.2,93.6,21.2};
double aa_nbin_err[7]={71.3,0,55.9,45.85,34.15,20.45,7.25};
double aa_npart[7]={352.4,-1,234.6,166.7,115.5,62.4,20.9};
double aa_npart_err[7]={3.7,-1,8.8,9.8,9.95,9.35,5.8};
double auau_npart[6]={352.4,234.6,166.7,115.5,62.4,20.9};
double auau_npart_err[6]={3.7,8.8,9.8,9.95,9.35,5.8};

TH1D** hist_auau(const char* filename="/home/tl543/pp_reference/HEPData-ins619063-v1-Table_1.root"){
    TFile* file=new TFile(filename);
    TDirectoryFile* table=(TDirectoryFile*)file->Get("Table 1");
    TH1D* hist_aa[7],*err_aa[7];
    TH1D** result=(TH1D**)malloc(7*sizeof(TH1D*));

    for(int i=0;i<7;i++){
    	hist_aa[i]=(TH1D*)table->Get(Form("Hist1D_y%i",i+1));
	err_aa[i]=(TH1D*)table->Get(Form("Hist1D_y%i_e1",i+1));
	result[i]=new TH1D(Form("auau_spec_%i_%i",aa_bins[i],aa_bins[i+1]),Form("auau_spec_%i_%i",aa_bins[i],aa_bins[i+1]),nbins,xbins);
	for(int ibin=1;ibin<=hist_aa[i]->GetNbinsX();ibin++){
	    double value=hist_aa[i]->GetBinContent(ibin);
	    double err=err_aa[i]->GetBinContent(ibin);

	    result[i]->SetBinContent(ibin+1,value);
	    result[i]->SetBinError(ibin+1,err);
	}
    }
    return result;
}

TH1D** hist_raa(const char* filename="/home/tl543/pp_reference/HEPData-ins619063-v1-Table_3.root"){
    TFile* file=new TFile(filename);
    TDirectoryFile* table=(TDirectoryFile*)file->Get("Table 3");
    TH1D* hist[6],*err[6];
    TH1D** result=(TH1D**)malloc(6*sizeof(TH1D*));

    for(int i=0;i<6;i++){
	hist[i]=(TH1D*)table->Get(Form("Hist1D_y%i",i+1));
	err[i]=(TH1D*)table->Get(Form("Hist1D_y%i_e1",i+1));
	int icent=(i>=1)?i+1:i;
	result[i]=new TH1D(Form("raa_%i_%i",aa_bins[icent],aa_bins[icent+1]),Form("raa_%i_%i",aa_bins[icent],aa_bins[icent+1]),nbins,xbins);
	for(int ibin=1;ibin<=hist[i]->GetNbinsX();ibin++){
	    double value=hist[i]->GetBinContent(ibin);
	    double error=err[i]->GetBinContent(ibin);
	    result[i]->SetBinContent(ibin+3,value);
	    result[i]->SetBinError(ibin+3,error);
	}
    }

    return result;

}


double dau_nbin[2]={15.1,7.51};
double dau_nbin_err[2]={1.3,0.39};
double dau_npart[2]={15.7,8.31};
double dau_npart_err[2]={1.2,0.37};

//index 0 stands for 0-20%
//index 1 stands for minbias
TH1D** hist_dau(const char* filename="/home/tl543/pp_reference/HEPData-ins621394-v1-Figure_2.root"){
    TFile* file=new TFile(filename);
    TDirectoryFile* table=(TDirectoryFile*)file->Get("Figure 2");
    TH1D* hist[2],*err[2];
    TH1D** result=(TH1D**)malloc(2*sizeof(TH1D*));
    for(int i=0;i<2;i++){
	hist[i]=(TH1D*)table->Get(Form("Hist1D_y%i",i+1));
	err[i]=(TH1D*)table->Get(Form("Hist1D_y%i_e1",i+1));
	result[i]=new TH1D(Form("dAu_%i",i),Form("dAu_%i",i),nbins,xbins);
//	result[i]->SetTitle(hist[i]->GetYaxis()->GetTitle());
	for(int ibin=1;ibin<=hist[i]->GetNbinsX();ibin++){
	    double value=hist[i]->GetBinContent(ibin);
	    double error=err[i]->GetBinContent(ibin);
	    result[i]->SetBinContent(ibin+9,value);
	    result[i]->SetBinError(ibin+9,error);
	}
    }
    return result;
}

TGraphErrors* cucu_pion(){
    const char* filename="/home/tl543/pp_reference/HEPData-ins837075-v1-Figure_3.root";
    TFile* file=new TFile(filename);
    TDirectoryFile* fig3=(TDirectoryFile*)file->Get("Figure 3 (b)");
    TGraphErrors* result=(TGraphErrors*)fig3->Get("Graph1D_y1");
    return result;
}


TGraph** wilke_npart_raa(){
double ru[16]={0.95718,0.937,0.916,0.887,0.854,0.827,0.791,0.751,0.713,0.672,0.641,0.601,0.562,0.522,0.485,0.453};
double zr[16]={0.96376,0.944,0.924,0.898,0.867,0.837,0.799,0.761,0.722,0.682,0.649,0.609,0.568,0.527,0.486,0.455};
double npart[16]={8.1437,10.557,13.997,18.069,22.904,28.884,35.883,43.772,53.952,64.513,76.347,89.962,106.0,124.96,147.1,167.1};

TGraph** result=(TGraph**)malloc(2*sizeof(TGraph*));
result[0]=new TGraph(16,npart,ru);
result[1]=new TGraph(16,npart,zr);
return result;
}

TGraph** wilke_pt_raa(){
double x_axis[11]={2.63,2.83,3.12,3.52,4.06,4.71,5.52,6.47,7.49,8.49,9.52};
double deltax[11]={0.2,0.2,0.35,0.45,0.6,0.7,0.9,1,1,1,1};
double cent[5][11]={
{1.01631,1.01548,1.01476,1.01429,1.0134,1.01274,1.01214,1.01214,1.01048,1.01167,1.01095},
{1.03095,1.02976,1.02833,1.02726,1.02571,1.02464,1.02333,1.02333,1.02048,1.02238,1.02095},
{1.05452,1.05286,1.05071,1.04929,1.04714,1.04548,1.04357,1.04369,1.03917,1.04214,1.04},
{1.08,1.0781,1.07571,1.07405,1.0719,1.07,1.06786,1.0681,1.0631,1.06643,1.06405},
{1.07786,1.07667,1.07548,1.07452,1.07333,1.07226,1.07107,1.07119,1.06833,1.07024,1.06893}
};

TGraph** result=(TGraph**)malloc(5*sizeof(TGraph*));
for(int i=0;i<5;i++){
  result[i]=new TGraph(11,x_axis,cent[i]);
  for(int ib=0;ib<11;ib++){
    x_axis[ib]+=0.07*deltax[ib];
  }
  
}
return result;
}



TGraphErrors** phenix_uu_pion(){
double npart[4]={17.8,64.8,159,330};
double npart_err[4]={0};
double raa[4]={0.61,0.48,0.33,0.19};
double raa_stat[4]={0.011,0.005,0.003,0.0016};
double raa_sys_err[4]={0.18,0.1,0.063,0.037};
TGraphErrors** result=(TGraphErrors**)malloc(2*sizeof(TGraphErrors*));
result[0]=new TGraphErrors(4,npart,raa,npart_err,raa_stat);
result[1]=new TGraphErrors(4,npart,raa,npart_err,raa_sys_err);
return result;
}

TGraphErrors** phenix_cuau_pion(){
double npart[4]={177.2,132.4,80.4,34.9};
double npart_err[4]={5.2,3.7,3.3,2.8};
double npart_width[4];
for(int i=0;i<4;i++)npart_width[i]=0.03*npart[i];
double raa[4]={0.3559419,0.4230856,0.5657007,0.837403};    
double err_stat[4]={0.002515,0.002925,0.003118,0.004808};
double err_sys[4]={0.059,0.07,0.094,0.139};
TGraphErrors** result=(TGraphErrors**)malloc(2*sizeof(TGraphErrors*));
result[0]=new TGraphErrors(4,npart,raa,npart_err,err_stat);
result[1]=new TGraphErrors(4,npart,raa,npart_width,err_sys);
return result;
}

TGraphErrors** phenix_auau_pion(){
double npart[9]={6.3364,13.523,25.886,45.282,74.645,114.05,167.06,235.06,325.09};
double npart_err[9]={0};
double npart_width[9];
for(int i=0;i<9;i++)npart_width[i]=0.03*npart[i];
double raa[9]={0.7786,0.80101,0.74364,0.64549,0.52,0.40392,0.325,0.259,0.19462};
double err_stat[9]={0.0278,0.02,0.0128,0.00878,0.00614,0,0.00329,0.0026,0};
double err_sys[9]={0.2265,0.2918,0.2271,0.1456,0.1054523,0.058263,0.08227,0.0761842,0.027339};

TGraphErrors** result=(TGraphErrors**)malloc(2*sizeof(TGraphErrors*));
result[0]=new TGraphErrors(9,npart,raa,npart_err,err_stat);
result[1]=new TGraphErrors(9,npart,raa,npart_width,err_sys);
return result;


}


TGraphErrors** hgpythia_ref_old(){
TFile* ru_file=new TFile("/home/tl543/hgpythia_ana/hgpythia_ru.root");
TFile* zr_file=new TFile("/home/tl543/hgpythia_ana/hgpythia_zr.root");

TGraphErrors** result=(TGraphErrors**)malloc(2*sizeof(TGraphErrors*));
TGraphErrors* buf=(TGraphErrors*)ru_file->Get("Graph");
result[0]=(TGraphErrors*)buf->Clone();
result[0]->SetName("hgpythia_ru");

TGraphErrors* buf1=(TGraphErrors*)zr_file->Get("Graph");
result[1]=(TGraphErrors*)buf1->Clone();
result[1]->SetName("hgpythia_zr");
return result;

}

TGraphErrors** hgpythia_ref(
const char* ru_name="/home/tl543/hgpythia_ana/ru_sig42_npart_yield.root",
const char* zr_name="/home/tl543/hgpythia_ana/zr_sig42_npart_yield.root",
const char* proton_name="/home/tl543/project/hg-pythia/hist_proton.root",
const char* keyword="_sig42"
){
TFile* ru_file=new TFile(ru_name);
TFile* zr_file=new TFile(zr_name);
TFile* proton_file=new TFile(proton_name);

TGraphErrors** result=(TGraphErrors**)malloc(2*sizeof(TGraphErrors*));
TGraphErrors* buf=(TGraphErrors*)ru_file->Get(Form("ru%s_npart_ych5",keyword));
result[0]=(TGraphErrors*)buf->Clone();
result[0]->SetName("hgpythia_ru");

TGraphErrors* buf1=(TGraphErrors*)zr_file->Get(Form("zr%s_npart_ych5",keyword));
result[1]=(TGraphErrors*)buf1->Clone();
result[1]->SetName("hgpythia_zr");

TH1F* mult_ych5_1=(TH1F*)proton_file->Get("mult_ych5_1");
TH2F* ncoll_ncolT=(TH2F*)proton_file->Get("ncoll_ncolT");
double nppentries=ncoll_ncolT->GetEntries();
double err_ych5;
double pp_ych5=mult_ych5_1->IntegralAndError(1,-1,err_ych5);
err_ych5/=pp_ych5;
pp_ych5/=nppentries;
for(int i=0;i<2;i++){
  int nbin=result[i]->GetN();
  for(int ib=0;ib<nbin;ib++){
    double val=result[i]->GetPointY(ib);

    double err=result[i]->GetErrorY(ib)/val;
    err=TMath::Sqrt(err*err+err_ych5*err_ych5);
    val/=pp_ych5;
    err*=val;
    result[i]->SetPointY(ib,val);
    result[i]->SetPointError(ib,result[i]->GetErrorX(ib),err);
  }
}

return result;

}

TGraphErrors** hgpythia_nhard(
const char* ru_name="/home/tl543/hgpythia_ana/ru_sig42_npart_yield.root",
const char* zr_name="/home/tl543/hgpythia_ana/zr_sig42_npart_yield.root",
const char* proton_name="/home/tl543/project/hg-pythia/hist_proton.root",
const char* keyword="_sig42"
){

TFile* ru_file=new TFile(ru_name);
TFile* zr_file=new TFile(zr_name);
TFile* proton_file=new TFile(proton_name);
TGraphErrors** result=(TGraphErrors**)malloc(2*sizeof(TGraphErrors*));
TGraphErrors* buf=(TGraphErrors*)ru_file->Get(Form("ru%s_npart_nhard",keyword));
result[0]=(TGraphErrors*)buf->Clone();
result[0]->SetName("hgpythia_ru");

TGraphErrors* buf1=(TGraphErrors*)zr_file->Get(Form("zr%s_npart_nhard",keyword));
result[1]=(TGraphErrors*)buf1->Clone();
result[1]->SetName("hgpythia_zr");

TH2F* mult_nmpi_1=(TH2F*)proton_file->Get("mult_nmpi_1");
TH1F* nmpi=(TH1F*)mult_nmpi_1->ProjectionY();
double avg_mpi=nmpi->GetMean();
double err_mpi=nmpi->GetStdDev()/TMath::Sqrt(nmpi->GetEntries()-1);
err_mpi/=avg_mpi;
for(int i=0;i<2;i++){
  int nbin=result[i]->GetN();
  for(int ib=0;ib<nbin;ib++){
    double val=result[i]->GetPointY(ib);
    double err=result[i]->GetErrorY(ib)/val;
    err=TMath::Sqrt(err*err+err_mpi*err_mpi);
    val/=avg_mpi;
    err*=val;
    result[i]->SetPointY(ib,val);
    result[i]->SetPointError(ib,result[i]->GetErrorX(ib),err);
  }
}

return result;

}

void phenix_set_style(TGraphErrors** g,int markerstyle,int color,int linewidth){
g[0]->SetMarkerStyle(markerstyle);
g[0]->SetLineColor(color);
g[0]->SetMarkerColor(color);
g[0]->SetMarkerSize(2);
g[0]->SetLineWidth(linewidth);

g[1]->SetMarkerSize(0);
g[1]->SetLineColor(color);
g[1]->SetFillColorAlpha(0,0);
g[1]->SetLineWidth(1);

}

