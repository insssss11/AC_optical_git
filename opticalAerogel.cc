

int opticalAerogel(void)
{
  const Int_t cm = 1;
       Double_t pE[] =
                       { 2.034, 2.068, 2.103, 2.139,
                                         2.177, 2.216, 2.256, 2.298,
                                                         2.341, 2.386, 2.433, 2.481,
                                                                         2.532, 2.585, 2.640, 2.697,
                                                                                         2.757, 2.820, 2.885, 2.954,
                                                                                                         3.026, 3.102, 3.181, 3.265,
                                                                                                                         3.353, 3.446, 3.545, 3.649,
                                                                                                                                         3.760, 3.877, 4.002, 4.136 };
       const Int_t nEntries = sizeof(pE)/sizeof(Double_t);
           Double_t absorption[] =
                          {9.695*cm,  9.295*cm,  8.836*cm,  8.419*cm,
                                           7.964*cm, 7.553*cm,7.181*cm, 6.734*cm,
                                                          6.336*cm, 5.938*cm, 5.583*cm, 5.231*cm,
                                                                       4.859*cm, 4.532*cm, 4.220*cm, 3.923*cm,
                                                                                    3.609*cm, 3.336*cm, 3.057*cm, 2.804*cm,
                                                                                                 2.564*cm, 2.330*cm, 2.113*cm, 1.914*cm,
                                                                                                              1.725*cm, 1.547*cm, 1.370*cm, 1.228*cm,
                                                                                                                           1.085*cm, 0.955*cm, 0.835*cm, 0.726*cm };
    Double_t Lambda_scat=146.846;
    
    TGraph *abs1 = new TGraph(nEntries, pE, absorption);
    TGraph *abs2 = new TGraph(*abs1);
    
    TF1 *f1 = new TF1("f1", "[0]*pow(x,-2)",  0, 10);
    TF1 *f2 = new TF1("f2", "[0]*exp(-[1]*x)", 0, 10);
    
    
    abs1->Fit(f1,"V");
    abs1->SetTitle("fit model : A * x^(-2)");
    abs1->GetXaxis()->SetTitle("eV");
    abs1->GetYaxis()->SetTitle("cm");
    
    TCanvas *c1 = new TCanvas();
    abs1->Draw();
    
    abs2->Fit(f2, "V");
    abs2->SetTitle("fit model : A * exp(-B *x)");
    abs2->GetXaxis()->SetTitle("eV");
    abs2->GetYaxis()->SetTitle("cm");
    
    TCanvas *c2 = new TCanvas();
    abs2->Draw();
    return 1;
}

