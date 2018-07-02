// written by Hyunmin Yang in HANUL
// supervisor : Prof Ahn
// this macro draw graph from csv file
#include <fstream>
#include <iostream>
#include <string>
#include "TGraph.h"
using namespace std;

int drawQE(void)
{
  ifstream file("quantumefficiency.txt", ios::in);
  if(!file.is_open())
  {
    cout << "File open failure" << endl;
  }

  Int_t size = 24, cnt = 0;
  string inStr[6];
  TGraph *QEwave  = new TGraph(size);
  TGraph *QEeV    = new TGraph(size);

  file >> inStr[0] >> inStr[1] >> inStr[2] >> inStr[3] >> inStr[4] >> inStr[5];
  while(!file.eof())
  {
    file >> inStr[0] >> inStr[1] >> inStr[2] >> inStr[3] >> inStr[4] >> inStr[5];
    QEwave->SetPoint(cnt, atof(inStr[0].c_str()), atof(inStr[5].c_str()));
    QEeV->SetPoint(cnt, atof(inStr[3].c_str()), atof(inStr[5].c_str()));
    cnt ++;
    cout << atof(inStr[0].c_str()) << " " << atof(inStr[5].c_str()) << endl;
  }
  TCanvas *c1 = new TCanvas("c1");
  
  QEwave->SetMarkerStyle(20);
  QEwave->SetMarkerSize(0.8);
  QEwave->SetMarkerColor(kRed);
  QEwave->SetLineWidth(3);
  QEwave->SetLineColor(kBlack);

  QEwave->SetTitle("QE of R5543(UV type)");
  QEwave->GetXaxis()->SetTitle("Wavelength(nm)");
  QEwave->GetYaxis()->SetTitle("QE(%)");
  QEwave->Draw("PCA");

  c1->Print("QEGraph.png");

  TCanvas *c2 = new TCanvas("c2");
  c2->cd();
  QEwave->SetMarkerStyle(20);
  QEwave->SetMarkerSize(0.8);
  QEwave->SetMarkerColor(kRed);
  QEwave->SetLineWidth(3);
  QEwave->SetLineColor(kBlack);

  QEwave->SetTitle("QE(log scale) of R5543(UV type)");
  QEwave->GetXaxis()->SetTitle("Wavelength(nm)");
  c2->SetLogy();
  c2->SetGrid();
  QEwave->GetYaxis()->SetTitle("QE(%)");
  QEwave->Draw("PCA");

  c2->Print("QEGraphLog.png");

  return 1;
}
