#include <TFile.h>
#include <TGraph.h>
#include <TTree.h>
#include <TString.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TH2F.h>
#include <TH3F.h>
#include <iostream>
#include <TLegend.h>
#include <TBranch.h>
#include <TClonesArray.h>
#include <TChain.h>
#include <TMath.h>
#include <TF1.h>
#include <TF2.h>
#include <TSystem.h>
#include <TLatex.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TGaxis.h>
#include <TPaveStats.h>
#include <TAxis.h>



void plot_thresholds_AND(){

	TCanvas *c1 = new TCanvas("c1","c1",600,650);
	c1->SetRightMargin(0.16);

	TH2F* h_XX_YY_ZZ = new TH2F("h_thresholds","h_thresholds",10,30,40,32,18,50);

	//v2
	/*
	//--> Rates: (11.0,1.0);
	h_XX_YY_ZZ->Fill(32,20,133);
	h_XX_YY_ZZ->Fill(32,21,133);
	h_XX_YY_ZZ->Fill(32,22,133);
	h_XX_YY_ZZ->Fill(32,23,129);
	h_XX_YY_ZZ->Fill(32,24,123);
	h_XX_YY_ZZ->Fill(32,25,117);
	h_XX_YY_ZZ->Fill(32,26,110);
	h_XX_YY_ZZ->Fill(32,27,102);
	h_XX_YY_ZZ->Fill(32,28,100);
	h_XX_YY_ZZ->Fill(32,29,99);
	h_XX_YY_ZZ->Fill(32,30,95);
	h_XX_YY_ZZ->Fill(32,31,91);
	h_XX_YY_ZZ->Fill(32,32,78);
	h_XX_YY_ZZ->Fill(32,33,76);
	h_XX_YY_ZZ->Fill(32,34,76);
	h_XX_YY_ZZ->Fill(32,35,76);


	//--> Rates: (10.0,2.0);
	h_XX_YY_ZZ->Fill(33,20,122);
	h_XX_YY_ZZ->Fill(33,21,121);
	h_XX_YY_ZZ->Fill(33,22,119);
	h_XX_YY_ZZ->Fill(33,23,116);
	h_XX_YY_ZZ->Fill(33,24,104);
	h_XX_YY_ZZ->Fill(33,25,95);
	h_XX_YY_ZZ->Fill(33,26,84);
	h_XX_YY_ZZ->Fill(33,27,78);
	h_XX_YY_ZZ->Fill(33,28,75);
	h_XX_YY_ZZ->Fill(33,29,72);
	h_XX_YY_ZZ->Fill(33,30,65);
	h_XX_YY_ZZ->Fill(33,31,61);
	h_XX_YY_ZZ->Fill(33,32,59);
	h_XX_YY_ZZ->Fill(33,33,57);
	h_XX_YY_ZZ->Fill(33,34,54);
	h_XX_YY_ZZ->Fill(33,35,54);

	//--> Rates: (9.0,3.0);
	h_XX_YY_ZZ->Fill(34,20,114);
	h_XX_YY_ZZ->Fill(34,21,112);
	h_XX_YY_ZZ->Fill(34,22,109);
	h_XX_YY_ZZ->Fill(34,23,105);
	h_XX_YY_ZZ->Fill(34,24,95);
	h_XX_YY_ZZ->Fill(34,25,85);
	h_XX_YY_ZZ->Fill(34,26,73);
	h_XX_YY_ZZ->Fill(34,27,67);
	h_XX_YY_ZZ->Fill(34,28,61);
	h_XX_YY_ZZ->Fill(34,29,55);
	h_XX_YY_ZZ->Fill(34,30,53);
	h_XX_YY_ZZ->Fill(34,31,50);
	h_XX_YY_ZZ->Fill(34,32,46);
	h_XX_YY_ZZ->Fill(34,33,45);
	h_XX_YY_ZZ->Fill(34,34,43);
	h_XX_YY_ZZ->Fill(34,35,43);

	//--> Rates: (8.0,4.0);
	h_XX_YY_ZZ->Fill(35,20,108);
	h_XX_YY_ZZ->Fill(35,21,105);
	h_XX_YY_ZZ->Fill(35,22,103);
	h_XX_YY_ZZ->Fill(35,23,99);
	h_XX_YY_ZZ->Fill(35,24,90);
	h_XX_YY_ZZ->Fill(35,25,78);
	h_XX_YY_ZZ->Fill(35,26,63);
	h_XX_YY_ZZ->Fill(35,27,59);
	h_XX_YY_ZZ->Fill(35,28,54);
	h_XX_YY_ZZ->Fill(35,29,51);
	h_XX_YY_ZZ->Fill(35,30,46);
	h_XX_YY_ZZ->Fill(35,31,43);
	h_XX_YY_ZZ->Fill(35,32,40);
	h_XX_YY_ZZ->Fill(35,33,38);
	h_XX_YY_ZZ->Fill(35,34,36);
	h_XX_YY_ZZ->Fill(35,35,36);

	//--> Rates: (7.4,4.6);
	h_XX_YY_ZZ->Fill(36,20,104);
	h_XX_YY_ZZ->Fill(36,21,103);
	h_XX_YY_ZZ->Fill(36,22,100);
	h_XX_YY_ZZ->Fill(36,23,95);
	h_XX_YY_ZZ->Fill(36,24,87);
	h_XX_YY_ZZ->Fill(36,25,75);
	h_XX_YY_ZZ->Fill(36,26,59);
	h_XX_YY_ZZ->Fill(36,27,55);
	h_XX_YY_ZZ->Fill(36,28,52);
	h_XX_YY_ZZ->Fill(36,29,46);
	h_XX_YY_ZZ->Fill(36,30,43);
	h_XX_YY_ZZ->Fill(36,31,40);
	h_XX_YY_ZZ->Fill(36,32,37);
	h_XX_YY_ZZ->Fill(36,33,36);
	h_XX_YY_ZZ->Fill(36,34,33);
	h_XX_YY_ZZ->Fill(36,35,32);

    //--> Rates: (7.2,4.8);
	h_XX_YY_ZZ->Fill(37,20,104);
    h_XX_YY_ZZ->Fill(37,21,102);
    h_XX_YY_ZZ->Fill(37,22,99);
    h_XX_YY_ZZ->Fill(37,23,94);
    h_XX_YY_ZZ->Fill(37,24,87);
    h_XX_YY_ZZ->Fill(37,25,74);
    h_XX_YY_ZZ->Fill(37,26,58);
    h_XX_YY_ZZ->Fill(37,27,54);
    h_XX_YY_ZZ->Fill(37,28,51);
    h_XX_YY_ZZ->Fill(37,29,45);
    h_XX_YY_ZZ->Fill(37,30,43);
    h_XX_YY_ZZ->Fill(37,31,39);
    h_XX_YY_ZZ->Fill(37,32,36);
    h_XX_YY_ZZ->Fill(37,33,34);
    h_XX_YY_ZZ->Fill(37,34,32);
    h_XX_YY_ZZ->Fill(37,35,31);

	//--> Rates: (7.0,5.0);
	h_XX_YY_ZZ->Fill(38,20,104);
	h_XX_YY_ZZ->Fill(38,21,100);
	h_XX_YY_ZZ->Fill(38,22,97);
	h_XX_YY_ZZ->Fill(38,23,93);
	h_XX_YY_ZZ->Fill(38,24,86);
	h_XX_YY_ZZ->Fill(38,25,73);
	h_XX_YY_ZZ->Fill(38,26,57);
	h_XX_YY_ZZ->Fill(38,27,53);
	h_XX_YY_ZZ->Fill(38,28,50);
	h_XX_YY_ZZ->Fill(38,29,44);
	h_XX_YY_ZZ->Fill(38,30,41);
	h_XX_YY_ZZ->Fill(38,31,38);
	h_XX_YY_ZZ->Fill(38,32,36);
	h_XX_YY_ZZ->Fill(38,33,33);
	h_XX_YY_ZZ->Fill(38,34,32);
	h_XX_YY_ZZ->Fill(38,35,31);

	//--> Rates: (6.0,6.0);
	h_XX_YY_ZZ->Fill(39,20,99);
	h_XX_YY_ZZ->Fill(39,21,96);
	h_XX_YY_ZZ->Fill(39,22,93);
	h_XX_YY_ZZ->Fill(39,23,90);
	h_XX_YY_ZZ->Fill(39,24,82);
	h_XX_YY_ZZ->Fill(39,25,69);
	h_XX_YY_ZZ->Fill(39,26,53);
	h_XX_YY_ZZ->Fill(39,27,50);
	h_XX_YY_ZZ->Fill(39,28,45);
	h_XX_YY_ZZ->Fill(39,29,40);
	h_XX_YY_ZZ->Fill(39,30,37);
	h_XX_YY_ZZ->Fill(39,31,34);
	h_XX_YY_ZZ->Fill(39,32,32);
	h_XX_YY_ZZ->Fill(39,33,30);
	h_XX_YY_ZZ->Fill(39,34,26);
	h_XX_YY_ZZ->Fill(39,35,25);

	//--> Rates: (5.8,6.2);
	h_XX_YY_ZZ->Fill(40,20,98);
	h_XX_YY_ZZ->Fill(40,21,95);
	h_XX_YY_ZZ->Fill(40,22,92);
	h_XX_YY_ZZ->Fill(40,23,89);
	h_XX_YY_ZZ->Fill(40,24,82);
	h_XX_YY_ZZ->Fill(40,25,67);
	h_XX_YY_ZZ->Fill(40,26,53);
	h_XX_YY_ZZ->Fill(40,27,48);
	h_XX_YY_ZZ->Fill(40,28,44);
	h_XX_YY_ZZ->Fill(40,29,39);
	h_XX_YY_ZZ->Fill(40,30,36);
	h_XX_YY_ZZ->Fill(40,31,34);
	h_XX_YY_ZZ->Fill(40,32,31);
	h_XX_YY_ZZ->Fill(40,33,30);
	h_XX_YY_ZZ->Fill(40,34,26);
	h_XX_YY_ZZ->Fill(40,35,23);
	h_XX_YY_ZZ->Fill(40,35,23);*/

	//v3
	h_XX_YY_ZZ->Fill(32,20,170);
	h_XX_YY_ZZ->Fill(32,21,170);
	h_XX_YY_ZZ->Fill(32,22,170);
	h_XX_YY_ZZ->Fill(32,23,170);
	h_XX_YY_ZZ->Fill(32,24,162);
	h_XX_YY_ZZ->Fill(32,25,140);
	h_XX_YY_ZZ->Fill(32,26,136);
	h_XX_YY_ZZ->Fill(32,27,136);
	h_XX_YY_ZZ->Fill(32,28,136);
	h_XX_YY_ZZ->Fill(32,29,136);
	h_XX_YY_ZZ->Fill(32,30,136);
	h_XX_YY_ZZ->Fill(32,31,136);
	h_XX_YY_ZZ->Fill(32,32,136);
	h_XX_YY_ZZ->Fill(32,33,136);
	h_XX_YY_ZZ->Fill(32,34,136);
	
	h_XX_YY_ZZ->Fill(33,20,130);
	h_XX_YY_ZZ->Fill(33,21,130);
	h_XX_YY_ZZ->Fill(33,22,126);
	h_XX_YY_ZZ->Fill(33,23,122);
	h_XX_YY_ZZ->Fill(33,24,112);
	h_XX_YY_ZZ->Fill(33,25,102);
	h_XX_YY_ZZ->Fill(33,26,96);
	h_XX_YY_ZZ->Fill(33,27,96);
	h_XX_YY_ZZ->Fill(33,28,92);
	h_XX_YY_ZZ->Fill(33,29,78);
	h_XX_YY_ZZ->Fill(33,30,76);
	h_XX_YY_ZZ->Fill(33,31,74);
	h_XX_YY_ZZ->Fill(33,32,70);
	h_XX_YY_ZZ->Fill(33,33,66);
	h_XX_YY_ZZ->Fill(33,34,66);
	
	h_XX_YY_ZZ->Fill(34,20,120);
	h_XX_YY_ZZ->Fill(34,21,120);
	h_XX_YY_ZZ->Fill(34,22,118);
	h_XX_YY_ZZ->Fill(34,23,112);
	h_XX_YY_ZZ->Fill(34,24,100);
	h_XX_YY_ZZ->Fill(34,25,92);
	h_XX_YY_ZZ->Fill(34,26,78);
	h_XX_YY_ZZ->Fill(34,27,76);
	h_XX_YY_ZZ->Fill(34,28,74);
	h_XX_YY_ZZ->Fill(34,29,64);
	h_XX_YY_ZZ->Fill(34,30,60);
	h_XX_YY_ZZ->Fill(34,31,56);
	h_XX_YY_ZZ->Fill(34,32,54);
	h_XX_YY_ZZ->Fill(34,33,54);
	h_XX_YY_ZZ->Fill(34,34,52);
	
	h_XX_YY_ZZ->Fill(35,20,114);
	h_XX_YY_ZZ->Fill(35,21,110);
	h_XX_YY_ZZ->Fill(35,22,108);
	h_XX_YY_ZZ->Fill(35,23,104);
	h_XX_YY_ZZ->Fill(35,24,94);
	h_XX_YY_ZZ->Fill(35,25,84);
	h_XX_YY_ZZ->Fill(35,26,70);
	h_XX_YY_ZZ->Fill(35,27,64);
	h_XX_YY_ZZ->Fill(35,28,60);
	h_XX_YY_ZZ->Fill(35,29,54);
	h_XX_YY_ZZ->Fill(35,30,52);
	h_XX_YY_ZZ->Fill(35,31,48);
	h_XX_YY_ZZ->Fill(35,32,44);
	h_XX_YY_ZZ->Fill(35,33,44);
	h_XX_YY_ZZ->Fill(35,34,42);
	
	h_XX_YY_ZZ->Fill(36,20,110);
	h_XX_YY_ZZ->Fill(36,21,108);
	h_XX_YY_ZZ->Fill(36,22,104);
	h_XX_YY_ZZ->Fill(36,23,100);
	h_XX_YY_ZZ->Fill(36,24,92);
	h_XX_YY_ZZ->Fill(36,25,80);
	h_XX_YY_ZZ->Fill(36,26,66);
	h_XX_YY_ZZ->Fill(36,27,60);
	h_XX_YY_ZZ->Fill(36,28,56);
	h_XX_YY_ZZ->Fill(36,29,52);
	h_XX_YY_ZZ->Fill(36,30,48);
	h_XX_YY_ZZ->Fill(36,31,44);
	h_XX_YY_ZZ->Fill(36,32,42);
	h_XX_YY_ZZ->Fill(36,33,40);
	h_XX_YY_ZZ->Fill(36,34,38);
	
	h_XX_YY_ZZ->Fill(37,20,108);
	h_XX_YY_ZZ->Fill(37,21,106);
	h_XX_YY_ZZ->Fill(37,22,104);
	h_XX_YY_ZZ->Fill(37,23,100);
	h_XX_YY_ZZ->Fill(37,24,90);
	h_XX_YY_ZZ->Fill(37,25,78);
	h_XX_YY_ZZ->Fill(37,26,64);
	h_XX_YY_ZZ->Fill(37,27,60);
	h_XX_YY_ZZ->Fill(37,28,54);
	h_XX_YY_ZZ->Fill(37,29,50);
	h_XX_YY_ZZ->Fill(37,30,46);
	h_XX_YY_ZZ->Fill(37,31,44);
	h_XX_YY_ZZ->Fill(37,32,40);
	h_XX_YY_ZZ->Fill(37,33,38);
	h_XX_YY_ZZ->Fill(37,34,36);
	
	h_XX_YY_ZZ->Fill(38,20,104);
	h_XX_YY_ZZ->Fill(38,21,102);
	h_XX_YY_ZZ->Fill(38,22,100);
	h_XX_YY_ZZ->Fill(38,23,96);
	h_XX_YY_ZZ->Fill(38,24,88);
	h_XX_YY_ZZ->Fill(38,25,76);
	h_XX_YY_ZZ->Fill(38,26,58);
	h_XX_YY_ZZ->Fill(38,27,54);
	h_XX_YY_ZZ->Fill(38,28,52);
	h_XX_YY_ZZ->Fill(38,29,46);
	h_XX_YY_ZZ->Fill(38,30,44);
	h_XX_YY_ZZ->Fill(38,31,40);
	h_XX_YY_ZZ->Fill(38,32,36);
	h_XX_YY_ZZ->Fill(38,33,36);
	h_XX_YY_ZZ->Fill(38,34,34);
	
	h_XX_YY_ZZ->Fill(39,20,104);
	h_XX_YY_ZZ->Fill(39,21,100);
	h_XX_YY_ZZ->Fill(39,22,96);
	h_XX_YY_ZZ->Fill(39,23,92);
	h_XX_YY_ZZ->Fill(39,24,86);
	h_XX_YY_ZZ->Fill(39,25,74);
	h_XX_YY_ZZ->Fill(39,26,56);
	h_XX_YY_ZZ->Fill(39,27,52);
	h_XX_YY_ZZ->Fill(39,28,48);
	h_XX_YY_ZZ->Fill(39,29,44);
	h_XX_YY_ZZ->Fill(39,30,40);
	h_XX_YY_ZZ->Fill(39,31,38);
	h_XX_YY_ZZ->Fill(39,32,34);
	h_XX_YY_ZZ->Fill(39,33,32);
	h_XX_YY_ZZ->Fill(39,34,32);
	
	h_XX_YY_ZZ->Fill(40,20,102);
	h_XX_YY_ZZ->Fill(40,21,98);
	h_XX_YY_ZZ->Fill(40,22,96);
	h_XX_YY_ZZ->Fill(40,23,92);
	h_XX_YY_ZZ->Fill(40,24,84);
	h_XX_YY_ZZ->Fill(40,25,70);
	h_XX_YY_ZZ->Fill(40,26,54);
	h_XX_YY_ZZ->Fill(40,27,52);
	h_XX_YY_ZZ->Fill(40,28,46);
	h_XX_YY_ZZ->Fill(40,29,42);
	h_XX_YY_ZZ->Fill(40,30,38);
	h_XX_YY_ZZ->Fill(40,31,36);
	h_XX_YY_ZZ->Fill(40,32,32);
	h_XX_YY_ZZ->Fill(40,33,32);
	h_XX_YY_ZZ->Fill(40,34,30);

	h_XX_YY_ZZ->SetBit(TH1::kNoStats);

	TPaveText* tex_cms = new TPaveText(0.12,0.91,0.30,0.93,"NDC");
    tex_cms->AddText("CMS Internal");
    tex_cms->SetTextSize(0.035);
    tex_cms->SetFillStyle(0);
    tex_cms->SetBorderSize(0);

    TPaveText* tex_lumi = new TPaveText(0.64,0.91,0.78,0.93,"NDC");
    tex_lumi->AddText("96.0 pb^{-1} (13 TeV)");
    tex_lumi->SetTextSize(0.035);
    tex_lumi->SetFillStyle(0);
    tex_lumi->SetBorderSize(0);

    TPaveText* tex_run = new TPaveText(0.6,0.85,0.61,0.86,"NDC");
    tex_run->AddText("2018 Data, ZeroBias, <PU> ~ 50");
    tex_run->SetTextColor(0);
    tex_run->SetTextSize(0.03);
    tex_run->SetFillStyle(0);
    tex_run->SetBorderSize(0);

    TPaveText* tex_scale = new TPaveText(0.59,0.82,0.6,0.83,"NDC");
    tex_scale->AddText("Linearly scaled to 2.0E34 cm^{-2}s^{-1}");
    tex_scale->SetTextColor(0);
    tex_scale->SetTextSize(0.03);
    tex_scale->SetFillStyle(0);
    tex_scale->SetBorderSize(0);

    TPaveText* tex_cuts1 = new TPaveText(0.44,0.77,0.49,0.78,"NDC");
    tex_cuts1->AddText("DoubleIsoTauXXer2p1 AND");
    tex_cuts1->SetTextColor(0);
    tex_cuts1->SetTextSize(0.03);
    tex_cuts1->SetFillStyle(0);
    tex_cuts1->SetBorderSize(0);

    TPaveText* tex_cuts2 = new TPaveText(0.44,0.74,0.49,0.75,"NDC");
    tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
    tex_cuts2->SetTextColor(0);
    tex_cuts2->SetTextSize(0.03);
    tex_cuts2->SetFillStyle(0);
    tex_cuts2->SetBorderSize(0);

    TPaveText* tex_cuts3 = new TPaveText(0.74,0.76,0.79,0.77,"NDC");
    tex_cuts3->AddText("12 kHz");
    tex_cuts3->SetTextColor(0);
    tex_cuts3->SetTextSize(0.035);
    tex_cuts3->SetFillStyle(0);
    tex_cuts3->SetBorderSize(0);

    h_XX_YY_ZZ->SetTitle("");
    h_XX_YY_ZZ->GetXaxis()->SetTitleOffset(1.1);
    h_XX_YY_ZZ->GetZaxis()->SetTitleOffset(1.6);
    h_XX_YY_ZZ->GetXaxis()->SetTitle("XX [GeV]");
    h_XX_YY_ZZ->GetYaxis()->SetTitle("YY [GeV]");
    h_XX_YY_ZZ->GetZaxis()->SetTitle("ZZ [GeV]");
    h_XX_YY_ZZ->GetXaxis()->CenterLabels(true);
    h_XX_YY_ZZ->GetYaxis()->CenterLabels(true);
    h_XX_YY_ZZ->GetYaxis()->SetNdivisions(16);
    h_XX_YY_ZZ->GetXaxis()->SetNdivisions(9);
    h_XX_YY_ZZ->GetXaxis()->SetRangeUser(32.,41.);
    h_XX_YY_ZZ->GetYaxis()->SetRangeUser(20.,35.);
    h_XX_YY_ZZ->GetZaxis()->SetRangeUser(19.,171.);
    gPad->Update();
    //h_XX_YY_ZZ->GetYaxis()->CenterLabels(true);
    //gPad->Update();

	h_XX_YY_ZZ->Draw("colz");
	tex_cms->Draw("same");
    tex_lumi->Draw("same");
    tex_run->Draw("same");
    tex_scale->Draw("same");
    tex_cuts1->Draw("same");
    tex_cuts2->Draw("same");
    tex_cuts3->Draw("same");

    c1->SaveAs("plots/thresholds_AND.pdf","pdf");


}


void plot_thresholds_OR(){

	TCanvas *c1 = new TCanvas("c1","c1",600,650);
	c1->SetRightMargin(0.16);

	TH2F* h_XX_YY_ZZ = new TH2F("h_thresholds","h_thresholds",10,30,40,32,18,50);

	h_XX_YY_ZZ->Fill(32,20,164);
	h_XX_YY_ZZ->Fill(32,21,164);
	h_XX_YY_ZZ->Fill(32,22,164);
	h_XX_YY_ZZ->Fill(32,23,150);
	h_XX_YY_ZZ->Fill(32,24,134);
	h_XX_YY_ZZ->Fill(32,25,126);
	h_XX_YY_ZZ->Fill(32,26,118);
	h_XX_YY_ZZ->Fill(32,27,118);
	h_XX_YY_ZZ->Fill(32,28,118);
	h_XX_YY_ZZ->Fill(32,29,100);
	h_XX_YY_ZZ->Fill(32,30,92);
	h_XX_YY_ZZ->Fill(32,31,52);
	h_XX_YY_ZZ->Fill(32,32,20);
	h_XX_YY_ZZ->Fill(32,33,20);
	h_XX_YY_ZZ->Fill(32,34,20);
	
	h_XX_YY_ZZ->Fill(33,20,124);
	h_XX_YY_ZZ->Fill(33,21,124);
	h_XX_YY_ZZ->Fill(33,22,120);
	h_XX_YY_ZZ->Fill(33,23,118);
	h_XX_YY_ZZ->Fill(33,24,104);
	h_XX_YY_ZZ->Fill(33,25,96);
	h_XX_YY_ZZ->Fill(33,26,76);
	h_XX_YY_ZZ->Fill(33,27,72);
	h_XX_YY_ZZ->Fill(33,28,60);
	h_XX_YY_ZZ->Fill(33,29,50);
	h_XX_YY_ZZ->Fill(33,30,40);
	h_XX_YY_ZZ->Fill(33,31,34);
	h_XX_YY_ZZ->Fill(33,32,20);
	h_XX_YY_ZZ->Fill(33,33,20);
	h_XX_YY_ZZ->Fill(33,34,20);

	h_XX_YY_ZZ->Fill(34,20,118);
	h_XX_YY_ZZ->Fill(34,21,114);
	h_XX_YY_ZZ->Fill(34,22,112);
	h_XX_YY_ZZ->Fill(34,23,108);
	h_XX_YY_ZZ->Fill(34,24,96);
	h_XX_YY_ZZ->Fill(34,25,86);
	h_XX_YY_ZZ->Fill(34,26,64);
	h_XX_YY_ZZ->Fill(34,27,60);
	h_XX_YY_ZZ->Fill(34,28,52);
	h_XX_YY_ZZ->Fill(34,29,44);
	h_XX_YY_ZZ->Fill(34,30,36);
	h_XX_YY_ZZ->Fill(34,31,30);
	h_XX_YY_ZZ->Fill(34,32,20);
	h_XX_YY_ZZ->Fill(34,33,20);
	h_XX_YY_ZZ->Fill(34,34,20);
	
	h_XX_YY_ZZ->Fill(35,20,110);
	h_XX_YY_ZZ->Fill(35,21,108);
	h_XX_YY_ZZ->Fill(35,22,104);
	h_XX_YY_ZZ->Fill(35,23,100);
	h_XX_YY_ZZ->Fill(35,24,90);
	h_XX_YY_ZZ->Fill(35,25,76);
	h_XX_YY_ZZ->Fill(35,26,58);
	h_XX_YY_ZZ->Fill(35,27,52);
	h_XX_YY_ZZ->Fill(35,28,46);
	h_XX_YY_ZZ->Fill(35,29,38);
	h_XX_YY_ZZ->Fill(35,30,32);
	h_XX_YY_ZZ->Fill(35,31,28);
	h_XX_YY_ZZ->Fill(35,32,20);
	h_XX_YY_ZZ->Fill(35,33,20);
	h_XX_YY_ZZ->Fill(35,34,20);
	
	h_XX_YY_ZZ->Fill(36,20,106);
	h_XX_YY_ZZ->Fill(36,21,106);
	h_XX_YY_ZZ->Fill(36,22,102);
	h_XX_YY_ZZ->Fill(36,23,96);
	h_XX_YY_ZZ->Fill(36,24,90);
	h_XX_YY_ZZ->Fill(36,25,76);
	h_XX_YY_ZZ->Fill(36,26,56);
	h_XX_YY_ZZ->Fill(36,27,50);
	h_XX_YY_ZZ->Fill(36,28,44);
	h_XX_YY_ZZ->Fill(36,29,38);
	h_XX_YY_ZZ->Fill(36,30,32);
	h_XX_YY_ZZ->Fill(36,31,28);
	h_XX_YY_ZZ->Fill(36,32,20);
	h_XX_YY_ZZ->Fill(36,33,20);
	h_XX_YY_ZZ->Fill(36,34,20);

	h_XX_YY_ZZ->Fill(37,20,106);
	h_XX_YY_ZZ->Fill(37,21,104);
	h_XX_YY_ZZ->Fill(37,22,100);
	h_XX_YY_ZZ->Fill(37,23,96);
	h_XX_YY_ZZ->Fill(37,24,88);
	h_XX_YY_ZZ->Fill(37,25,74);
	h_XX_YY_ZZ->Fill(37,26,54);
	h_XX_YY_ZZ->Fill(37,27,48);
	h_XX_YY_ZZ->Fill(37,28,44);
	h_XX_YY_ZZ->Fill(37,29,36);
	h_XX_YY_ZZ->Fill(37,30,32);
	h_XX_YY_ZZ->Fill(37,31,26);
	h_XX_YY_ZZ->Fill(37,32,20);
	h_XX_YY_ZZ->Fill(37,33,20);
	h_XX_YY_ZZ->Fill(37,34,20);
	
	h_XX_YY_ZZ->Fill(38,20,104);
	h_XX_YY_ZZ->Fill(38,21,100);
	h_XX_YY_ZZ->Fill(38,22,96);
	h_XX_YY_ZZ->Fill(38,23,92);
	h_XX_YY_ZZ->Fill(38,24,84);
	h_XX_YY_ZZ->Fill(38,25,70);
	h_XX_YY_ZZ->Fill(38,26,52);
	h_XX_YY_ZZ->Fill(38,27,46);
	h_XX_YY_ZZ->Fill(38,28,42);
	h_XX_YY_ZZ->Fill(38,29,34);
	h_XX_YY_ZZ->Fill(38,30,30);
	h_XX_YY_ZZ->Fill(38,31,26);
	h_XX_YY_ZZ->Fill(38,32,20);
	h_XX_YY_ZZ->Fill(38,33,20);
	h_XX_YY_ZZ->Fill(38,34,20);

	h_XX_YY_ZZ->Fill(39,20,100);
	h_XX_YY_ZZ->Fill(39,21,96);
	h_XX_YY_ZZ->Fill(39,22,94);
	h_XX_YY_ZZ->Fill(39,23,90);
	h_XX_YY_ZZ->Fill(39,24,84);
	h_XX_YY_ZZ->Fill(39,25,68);
	h_XX_YY_ZZ->Fill(39,26,52);
	h_XX_YY_ZZ->Fill(39,27,44);
	h_XX_YY_ZZ->Fill(39,28,40);
	h_XX_YY_ZZ->Fill(39,29,34);
	h_XX_YY_ZZ->Fill(39,30,30);
	h_XX_YY_ZZ->Fill(39,31,26);
	h_XX_YY_ZZ->Fill(39,32,20);
	h_XX_YY_ZZ->Fill(39,33,20);
	h_XX_YY_ZZ->Fill(39,34,20);
	
	h_XX_YY_ZZ->Fill(40,20,98);
	h_XX_YY_ZZ->Fill(40,21,96);
	h_XX_YY_ZZ->Fill(40,22,92);
	h_XX_YY_ZZ->Fill(40,23,90);
	h_XX_YY_ZZ->Fill(40,24,82);
	h_XX_YY_ZZ->Fill(40,25,64);
	h_XX_YY_ZZ->Fill(40,26,50);
	h_XX_YY_ZZ->Fill(40,27,44);
	h_XX_YY_ZZ->Fill(40,28,38);
	h_XX_YY_ZZ->Fill(40,29,34);
	h_XX_YY_ZZ->Fill(40,30,30);
	h_XX_YY_ZZ->Fill(40,31,26);
	h_XX_YY_ZZ->Fill(40,32,20);
	h_XX_YY_ZZ->Fill(40,33,20);
	h_XX_YY_ZZ->Fill(40,34,20);


	h_XX_YY_ZZ->SetBit(TH1::kNoStats);

	TPaveText* tex_cms = new TPaveText(0.12,0.91,0.30,0.93,"NDC");
    tex_cms->AddText("CMS Internal");
    tex_cms->SetTextSize(0.035);
    tex_cms->SetFillStyle(0);
    tex_cms->SetBorderSize(0);

    TPaveText* tex_lumi = new TPaveText(0.64,0.91,0.78,0.93,"NDC");
    tex_lumi->AddText("96.0 pb^{-1} (13 TeV)");
    tex_lumi->SetTextSize(0.035);
    tex_lumi->SetFillStyle(0);
    tex_lumi->SetBorderSize(0);

    TPaveText* tex_run = new TPaveText(0.6,0.85,0.61,0.86,"NDC");
    tex_run->AddText("2018 Data, ZeroBias, <PU> ~ 50");
    tex_run->SetTextColor(0);
    tex_run->SetTextSize(0.03);
    tex_run->SetFillStyle(0);
    tex_run->SetBorderSize(0);

    TPaveText* tex_scale = new TPaveText(0.59,0.82,0.6,0.83,"NDC");
    tex_scale->AddText("Linearly scaled to 2.0E34 cm^{-2}s^{-1}");
    tex_scale->SetTextColor(0);
    tex_scale->SetTextSize(0.03);
    tex_scale->SetFillStyle(0);
    tex_scale->SetBorderSize(0);

    TPaveText* tex_cuts1 = new TPaveText(0.44,0.77,0.49,0.78,"NDC");
    tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
    tex_cuts1->SetTextColor(0);
    tex_cuts1->SetTextSize(0.03);
    tex_cuts1->SetFillStyle(0);
    tex_cuts1->SetBorderSize(0);

    TPaveText* tex_cuts2 = new TPaveText(0.44,0.74,0.49,0.75,"NDC");
    tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
    tex_cuts2->SetTextColor(0);
    tex_cuts2->SetTextSize(0.03);
    tex_cuts2->SetFillStyle(0);
    tex_cuts2->SetBorderSize(0);

    TPaveText* tex_cuts3 = new TPaveText(0.74,0.76,0.79,0.77,"NDC");
    tex_cuts3->AddText("12 kHz");
    tex_cuts3->SetTextColor(0);
    tex_cuts3->SetTextSize(0.035);
    tex_cuts3->SetFillStyle(0);
    tex_cuts3->SetBorderSize(0);

    h_XX_YY_ZZ->SetTitle("");
    h_XX_YY_ZZ->GetXaxis()->SetTitleOffset(1.1);
    h_XX_YY_ZZ->GetZaxis()->SetTitleOffset(1.6);
    h_XX_YY_ZZ->GetXaxis()->SetTitle("XX [GeV]");
    h_XX_YY_ZZ->GetYaxis()->SetTitle("YY [GeV]");
    h_XX_YY_ZZ->GetZaxis()->SetTitle("ZZ [GeV]");
    h_XX_YY_ZZ->GetXaxis()->CenterLabels(true);
    h_XX_YY_ZZ->GetYaxis()->CenterLabels(true);
    h_XX_YY_ZZ->GetYaxis()->SetNdivisions(16);
    h_XX_YY_ZZ->GetXaxis()->SetNdivisions(9);
    h_XX_YY_ZZ->GetXaxis()->SetRangeUser(32.,41.);
    h_XX_YY_ZZ->GetYaxis()->SetRangeUser(20.,35.);
    h_XX_YY_ZZ->GetZaxis()->SetRangeUser(19.,171.);
    gPad->Update();
    //h_XX_YY_ZZ->GetYaxis()->CenterLabels(true);
    //gPad->Update();

	h_XX_YY_ZZ->Draw("colz");
	tex_cms->Draw("same");
    tex_lumi->Draw("same");
    tex_run->Draw("same");
    tex_scale->Draw("same");
    tex_cuts1->Draw("same");
    tex_cuts2->Draw("same");
    tex_cuts3->Draw("same");

    c1->SaveAs("plots/thresholds_OR.pdf","pdf");


}