void read_hep(const char* filename="HEPData-ins619063-v1-Table_1.root"){
  TFile* file=new TFile(filename);
  TDirectoryFile* table=(TDirectoryFile*)file->Get("Table 1");
//  TBrowser *b;
//  table->Browse(b);
  TGraphErrors* graph_pp_ref=(TGraphErrors*)table->Get("Graph1D_y9");
//  graph_pp_ref->Draw();

  TH1D* hist_pp_ref=(TH1D*)table->Get("Hist1D_y9");
//  hist_pp_ref->Draw();
  TH1D* err_pp_ref=(TH1D*)table->Get("Hist1D_y9_e1");
  for(int i=1;i<=hist_pp_ref->GetNbinsX();i++){
    double err=err_pp_ref->GetBinContent(i);
    hist_pp_ref->SetBinError(i,err);
  }
  TCanvas* hist=new TCanvas("hist");
  hist->Draw();
  hist->cd();
  hist_pp_ref->Draw();
//  hist->SetLogy();
  TCanvas* graph=new TCanvas("tgraph");
  graph->Draw();
  graph->cd();
//  graph->SetLogy();
  graph_pp_ref->Draw();
  hist_pp_ref->Draw("same");

  cout<<hist_pp_ref->GetNbinsX()<<endl;
  cout<<graph_pp_ref->GetN()<<endl;
  for(int i=0;i<graph_pp_ref->GetN();i++){
    double hist_value=hist_pp_ref->GetBinContent(i+1);
    double hist_err=err_pp_ref->GetBinContent(i+1);
    double graph_x,graph_y;
    graph_pp_ref->GetPoint(i,graph_x,graph_y);
    double graph_error=graph_pp_ref->GetErrorY(i);
    cout<<graph_x<<"\t"<<hist_value<<"\t"<<hist_err/graph_error<<endl;
  }

}
