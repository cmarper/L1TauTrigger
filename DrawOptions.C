#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <iostream>
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPaveText.h>
#include <TStyle.h>
#include <TROOT.h>
#include <sstream>
#include <TBranchElement.h>
#include <fstream>
#include "Fill_Isolation_TH3_MC_2017Layer1Calibration.C"

void PrintEfficiencyTargets(){

  TString CanvasName = "./PlotIsolation/Options";
  TString CanvasNamePdf = CanvasName ;
  CanvasNamePdf += ".pdf";
  TCanvas c(CanvasName.Data(),CanvasName.Data(),650,600);
  c.SetLeftMargin(0.15);
  c.SetGrid();
  //c.SetLogy();

  gStyle->SetOptStat(0000);

  TH1F* Efficiency_Progression_1 = new TH1F("Efficiency_Progression_1","Efficiency_Progression_1",80.,0.,80.);
  TH1F* Efficiency_Progression_2 = new TH1F("Efficiency_Progression_2","Efficiency_Progression_2",80.,0.,80.);
  TH1F* Efficiency_Progression_3 = new TH1F("Efficiency_Progression_3","Efficiency_Progression_3",80.,0.,80.);
  TH1F* Efficiency_Progression_4 = new TH1F("Efficiency_Progression_4","Efficiency_Progression_4",80.,0.,80.);
  TH1F* Efficiency_Progression_5 = new TH1F("Efficiency_Progression_5","Efficiency_Progression_5",80.,0.,80.);
  TH1F* Efficiency_Progression_6 = new TH1F("Efficiency_Progression_6","Efficiency_Progression_6",80.,0.,80.);
  TH1F* Efficiency_Progression_7 = new TH1F("Efficiency_Progression_7","Efficiency_Progression_7",80.,0.,80.);
  TH1F* Efficiency_Progression_8 = new TH1F("Efficiency_Progression_8","Efficiency_Progression_8",80.,0.,80.);
  TH1F* Efficiency_Progression_9 = new TH1F("Efficiency_Progression_9","Efficiency_Progression_9",80.,0.,80.);
  TH1F* Efficiency_Progression_10 = new TH1F("Efficiency_Progression_10","Efficiency_Progression_10",80.,0.,80.);
  TH1F* Efficiency_Progression_11 = new TH1F("Efficiency_Progression_11","Efficiency_Progression_11",80.,0.,80.);
  TH1F* Efficiency_Progression_12 = new TH1F("Efficiency_Progression_12","Efficiency_Progression_12",80.,0.,80.);
  TH1F* Efficiency_Progression_13 = new TH1F("Efficiency_Progression_13","Efficiency_Progression_13",80.,0.,80.);
  TH1F* Efficiency_Progression_14 = new TH1F("Efficiency_Progression_14","Efficiency_Progression_14",80.,0.,80.);
  TH1F* Efficiency_Progression_15 = new TH1F("Efficiency_Progression_15","Efficiency_Progression_15",80.,0.,80.);
  TH1F* Efficiency_Progression_16 = new TH1F("Efficiency_Progression_16","Efficiency_Progression_16",80.,0.,80.);
  TH1F* Efficiency_Progression_17 = new TH1F("Efficiency_Progression_17","Efficiency_Progression_17",80.,0.,80.);
  TH1F* Efficiency_Progression_18 = new TH1F("Efficiency_Progression_18","Efficiency_Progression_18",80.,0.,80.);
  TH1F* Efficiency_Progression_19 = new TH1F("Efficiency_Progression_19","Efficiency_Progression_19",80.,0.,80.);
  TH1F* Efficiency_Progression_20 = new TH1F("Efficiency_Progression_20","Efficiency_Progression_20",80.,0.,80.);
  TH1F* Efficiency_Progression_21 = new TH1F("Efficiency_Progression_21","Efficiency_Progression_21",80.,0.,80.);
  TH1F* Efficiency_Progression_22 = new TH1F("Efficiency_Progression_22","Efficiency_Progression_22",80.,0.,80.);

  for(UInt_t i = 1 ; i <= Efficiency_Progression_1->GetNbinsX() ; ++i)
    {
      Efficiency_Progression_1->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.1, 50.));
      Efficiency_Progression_2->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.4, 50.));
      Efficiency_Progression_3->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.5, 50.));
      Efficiency_Progression_4->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.6, 50.));
      Efficiency_Progression_5->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.7, 50.));
      Efficiency_Progression_6->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.5, 40.));
      Efficiency_Progression_7->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.5, 40.));
      Efficiency_Progression_8->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.5, 60.));
      Efficiency_Progression_9->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.6, 40.));
      Efficiency_Progression_10->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.7, 50.));
      Efficiency_Progression_11->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.7, 40.));
      Efficiency_Progression_12->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 20., 0.7, 35.));
      Efficiency_Progression_13->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 20., 0.6, 35.));
      Efficiency_Progression_14->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 20., 0.5, 35.));
      Efficiency_Progression_15->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 20., 0.7, 35.));
      Efficiency_Progression_16->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 23., 0.1, 30.));
      Efficiency_Progression_17->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 15., 0., 30.));
      Efficiency_Progression_18->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 20., 0., 35.));
      Efficiency_Progression_19->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 15., 0., 35.));
      Efficiency_Progression_20->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 10., 0., 35.));
      Efficiency_Progression_21->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 20., 0.8, 50.));
      Efficiency_Progression_22->SetBinContent(i,FindEfficiency_Progression(2.*Efficiency_Progression_1->GetBinLowEdge(i), 25., 0.7, 70.));
    }

  Efficiency_Progression_1->Draw();
  Efficiency_Progression_1->SetTitle("");
  Efficiency_Progression_1->GetXaxis()->SetTitle("p_{T}^{L1}");
  Efficiency_Progression_1->GetYaxis()->SetTitle("Target Efficiency");


  Efficiency_Progression_1->SetLineColor(51);
  Efficiency_Progression_2->SetLineColor(53);
  Efficiency_Progression_3->SetLineColor(57);
  Efficiency_Progression_4->SetLineColor(62);
  Efficiency_Progression_5->SetLineColor(65);
  Efficiency_Progression_6->SetLineColor(68);
  Efficiency_Progression_7->SetLineColor(71);
  Efficiency_Progression_8->SetLineColor(74);
  Efficiency_Progression_9->SetLineColor(86);
  Efficiency_Progression_10->SetLineColor(88);
  Efficiency_Progression_11->SetLineColor(91);
  Efficiency_Progression_12->SetLineColor(92);
  Efficiency_Progression_13->SetLineColor(95);
  Efficiency_Progression_14->SetLineColor(98);
  Efficiency_Progression_15->SetLineColor(50);
  Efficiency_Progression_16->SetLineColor(45);
  Efficiency_Progression_17->SetLineColor(42);
  Efficiency_Progression_18->SetLineColor(25);
  Efficiency_Progression_19->SetLineColor(28);
  Efficiency_Progression_20->SetLineColor(14);
  Efficiency_Progression_21->SetLineColor(12);
  Efficiency_Progression_22->SetLineColor(1);
  
  Efficiency_Progression_1->SetLineWidth(2);
  Efficiency_Progression_2->SetLineWidth(2);
  Efficiency_Progression_3->SetLineWidth(2);
  Efficiency_Progression_4->SetLineWidth(2);
  Efficiency_Progression_5->SetLineWidth(2);
  Efficiency_Progression_6->SetLineWidth(2);
  Efficiency_Progression_7->SetLineWidth(2);
  Efficiency_Progression_8->SetLineWidth(2);
  Efficiency_Progression_9->SetLineWidth(2);
  Efficiency_Progression_10->SetLineWidth(2);
  Efficiency_Progression_11->SetLineWidth(2);
  Efficiency_Progression_12->SetLineWidth(2);
  Efficiency_Progression_13->SetLineWidth(2);
  Efficiency_Progression_14->SetLineWidth(2);
  Efficiency_Progression_15->SetLineWidth(2);
  Efficiency_Progression_16->SetLineWidth(2);
  Efficiency_Progression_17->SetLineWidth(2);
  Efficiency_Progression_18->SetLineWidth(2);
  Efficiency_Progression_19->SetLineWidth(2);
  Efficiency_Progression_20->SetLineWidth(2);
  Efficiency_Progression_21->SetLineWidth(2);
  Efficiency_Progression_22->SetLineWidth(2);
  
  Efficiency_Progression_2->Draw("same");
  Efficiency_Progression_3->Draw("same");
  Efficiency_Progression_4->Draw("same");
  Efficiency_Progression_5->Draw("same");
  Efficiency_Progression_6->Draw("same");
  Efficiency_Progression_7->Draw("same");
  Efficiency_Progression_8->Draw("same");
  Efficiency_Progression_9->Draw("same");
  Efficiency_Progression_10->Draw("same");
  Efficiency_Progression_11->Draw("same");
  Efficiency_Progression_12->Draw("same");
  Efficiency_Progression_13->Draw("same");
  Efficiency_Progression_14->Draw("same");
  Efficiency_Progression_15->Draw("same");
  Efficiency_Progression_16->Draw("same");
  Efficiency_Progression_17->Draw("same");
  Efficiency_Progression_18->Draw("same");
  Efficiency_Progression_19->Draw("same");
  Efficiency_Progression_20->Draw("same");
  Efficiency_Progression_21->Draw("same");
  Efficiency_Progression_22->Draw("same");
 
  cout << "1: " << Efficiency_Progression_1->Integral() << endl;
  cout << "2: " << Efficiency_Progression_2->Integral() << endl;
  cout << "3: " << Efficiency_Progression_3->Integral() << endl;
  cout << "4: " << Efficiency_Progression_4->Integral() << endl;
  cout << "5: " << Efficiency_Progression_5->Integral() << endl;
  cout << "6: " << Efficiency_Progression_6->Integral() << endl;
  cout << "7: " << Efficiency_Progression_7->Integral() << endl;
  cout << "8: " << Efficiency_Progression_8->Integral() << endl;
  cout << "9: " << Efficiency_Progression_9->Integral() << endl;
  cout << "10: " << Efficiency_Progression_10->Integral() << endl;
  cout << "11: " << Efficiency_Progression_11->Integral() << endl;
  cout << "12: " << Efficiency_Progression_12->Integral() << endl;
  cout << "13: " << Efficiency_Progression_13->Integral() << endl;
  cout << "14: " << Efficiency_Progression_14->Integral() << endl;
  cout << "15: " << Efficiency_Progression_15->Integral() << endl;
  cout << "16: " << Efficiency_Progression_16->Integral() << endl;
  cout << "17: " << Efficiency_Progression_17->Integral() << endl;
  cout << "18: " << Efficiency_Progression_18->Integral() << endl;
  cout << "19: " << Efficiency_Progression_19->Integral() << endl;
  cout << "20: " << Efficiency_Progression_20->Integral() << endl;
  cout << "21: " << Efficiency_Progression_21->Integral() << endl;
  cout << "22: " << Efficiency_Progression_22->Integral() << endl;
 

  
  TLegend* leg = new TLegend(0.65,0.11,0.8,0.61);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);

  leg->AddEntry(Efficiency_Progression_1,"Option 1","L");
  leg->AddEntry(Efficiency_Progression_2,"Option 2","L");
  leg->AddEntry(Efficiency_Progression_3,"Option 3","L");
  leg->AddEntry(Efficiency_Progression_4,"Option 4","L");
  leg->AddEntry(Efficiency_Progression_5,"Option 5","L");
  leg->AddEntry(Efficiency_Progression_6,"Option 6","L");
  leg->AddEntry(Efficiency_Progression_7,"Option 7","L");
  leg->AddEntry(Efficiency_Progression_8,"Option 8","L");
  leg->AddEntry(Efficiency_Progression_9,"Option 9","L");
  leg->AddEntry(Efficiency_Progression_10,"Option 10","L");
  leg->AddEntry(Efficiency_Progression_11,"Option 11","L");
  leg->AddEntry(Efficiency_Progression_12,"Option 12","L");
  leg->AddEntry(Efficiency_Progression_13,"Option 13","L");
  leg->AddEntry(Efficiency_Progression_14,"Option 14","L");
  leg->AddEntry(Efficiency_Progression_15,"Option 15","L");
  leg->AddEntry(Efficiency_Progression_16,"Option 16","L");
  leg->AddEntry(Efficiency_Progression_17,"Option 17","L");
  leg->AddEntry(Efficiency_Progression_18,"Option 18","L");
  leg->AddEntry(Efficiency_Progression_19,"Option 19","L");
  leg->AddEntry(Efficiency_Progression_20,"Option 20","L");
  leg->AddEntry(Efficiency_Progression_21,"Option 21","L");
  leg->AddEntry(Efficiency_Progression_22,"Option 22","L");
 
  leg->Draw("same");
  
  
   
  c.SaveAs(CanvasNamePdf.Data());
}
