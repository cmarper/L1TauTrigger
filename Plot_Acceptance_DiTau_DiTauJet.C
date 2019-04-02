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



void plot_acceptance_0jet_VBF(){

	TCanvas *c1 = new TCanvas("c1","c1",600,650);
	c1->SetRightMargin(0.16);

	TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

    h_XX_YY_AccGain->Fill(32,20,0);
	h_XX_YY_AccGain->Fill(32,21,0);
	h_XX_YY_AccGain->Fill(32,22,0);
	h_XX_YY_AccGain->Fill(32,23,0);
	h_XX_YY_AccGain->Fill(32,24,0);
	h_XX_YY_AccGain->Fill(32,25,0);
	h_XX_YY_AccGain->Fill(32,26,0);
	h_XX_YY_AccGain->Fill(32,27,0);
    h_XX_YY_AccGain->Fill(32,28,0);
    h_XX_YY_AccGain->Fill(32,29,0);
	h_XX_YY_AccGain->Fill(32,30,0);
	h_XX_YY_AccGain->Fill(32,31,0);
	h_XX_YY_AccGain->Fill(32,32,0);
	h_XX_YY_AccGain->Fill(32,33,0);
	h_XX_YY_AccGain->Fill(32,34,0);

	h_XX_YY_AccGain->Fill(33,20,-7.87994);
	h_XX_YY_AccGain->Fill(33,21,-7.87994);
	h_XX_YY_AccGain->Fill(33,22,-7.87994);
	h_XX_YY_AccGain->Fill(33,23,-7.87994);
	h_XX_YY_AccGain->Fill(33,24,-7.87994);
    h_XX_YY_AccGain->Fill(33,25,-7.87994);
    h_XX_YY_AccGain->Fill(33,26,-7.87994);
    h_XX_YY_AccGain->Fill(33,27,-7.87994);
    h_XX_YY_AccGain->Fill(33,28,-7.87994);
    h_XX_YY_AccGain->Fill(33,29,-7.87994);
    h_XX_YY_AccGain->Fill(33,30,-7.87994);
    h_XX_YY_AccGain->Fill(33,31,-7.87994);
    h_XX_YY_AccGain->Fill(33,32,-7.87994);
    h_XX_YY_AccGain->Fill(33,33,-7.87994);
    h_XX_YY_AccGain->Fill(33,34,-7.87994);
     
    h_XX_YY_AccGain->Fill(34,20,-15.4961);
    h_XX_YY_AccGain->Fill(34,21,-15.4961);
    h_XX_YY_AccGain->Fill(34,22,-15.4961);
    h_XX_YY_AccGain->Fill(34,23,-15.4961);
    h_XX_YY_AccGain->Fill(34,24,-15.4961);
    h_XX_YY_AccGain->Fill(34,25,-15.4961);
    h_XX_YY_AccGain->Fill(34,26,-15.4961);
    h_XX_YY_AccGain->Fill(34,27,-15.4961);
    h_XX_YY_AccGain->Fill(34,28,-15.4961);
    h_XX_YY_AccGain->Fill(34,29,-15.4961);
    h_XX_YY_AccGain->Fill(34,30,-15.4961);
    h_XX_YY_AccGain->Fill(34,31,-15.4961);
    h_XX_YY_AccGain->Fill(34,32,-15.4961);
    h_XX_YY_AccGain->Fill(34,33,-15.4961);
    h_XX_YY_AccGain->Fill(34,34,-15.4961);
     
    h_XX_YY_AccGain->Fill(35,20,-22.0656);
    h_XX_YY_AccGain->Fill(35,21,-22.0656);
    h_XX_YY_AccGain->Fill(35,22,-22.0656);
    h_XX_YY_AccGain->Fill(35,23,-22.0656);
	h_XX_YY_AccGain->Fill(35,24,-22.0656);
	h_XX_YY_AccGain->Fill(35,25,-22.0656);
	h_XX_YY_AccGain->Fill(35,26,-22.0656);
	h_XX_YY_AccGain->Fill(35,27,-22.0656);
	h_XX_YY_AccGain->Fill(35,28,-22.0656);
	h_XX_YY_AccGain->Fill(35,29,-22.0656);
	h_XX_YY_AccGain->Fill(35,30,-22.0656);
	h_XX_YY_AccGain->Fill(35,31,-22.0656);
	h_XX_YY_AccGain->Fill(35,32,-22.0656);
    h_XX_YY_AccGain->Fill(35,33,-22.0656);
    h_XX_YY_AccGain->Fill(35,34,-22.0656);
     
    h_XX_YY_AccGain->Fill(36,20,-28.7216);
    h_XX_YY_AccGain->Fill(36,21,-28.7216);
    h_XX_YY_AccGain->Fill(36,22,-28.7216);
    h_XX_YY_AccGain->Fill(36,23,-28.7216);
	h_XX_YY_AccGain->Fill(36,24,-28.7216);
	h_XX_YY_AccGain->Fill(36,25,-28.7216);
	h_XX_YY_AccGain->Fill(36,26,-28.7216);
	h_XX_YY_AccGain->Fill(36,27,-28.7216);
	h_XX_YY_AccGain->Fill(36,28,-28.7216);
	h_XX_YY_AccGain->Fill(36,29,-28.7216);
	h_XX_YY_AccGain->Fill(36,30,-28.7216);
	h_XX_YY_AccGain->Fill(36,31,-28.7216);
	h_XX_YY_AccGain->Fill(36,32,-28.7216);
	h_XX_YY_AccGain->Fill(36,33,-28.7216);
	h_XX_YY_AccGain->Fill(36,34,-28.7216);
	 
	h_XX_YY_AccGain->Fill(37,20,-34.2012);
	h_XX_YY_AccGain->Fill(37,21,-34.2012);
	h_XX_YY_AccGain->Fill(37,22,-34.2012);
	h_XX_YY_AccGain->Fill(37,23,-34.2012);
	h_XX_YY_AccGain->Fill(37,24,-34.2012);
	h_XX_YY_AccGain->Fill(37,25,-34.2012);
	h_XX_YY_AccGain->Fill(37,26,-34.2012);
	h_XX_YY_AccGain->Fill(37,27,-34.2012);
	h_XX_YY_AccGain->Fill(37,28,-34.2012);
	h_XX_YY_AccGain->Fill(37,29,-34.2012);
	h_XX_YY_AccGain->Fill(37,30,-34.2012);
	h_XX_YY_AccGain->Fill(37,31,-34.2012);
	h_XX_YY_AccGain->Fill(37,32,-34.2012);
	h_XX_YY_AccGain->Fill(37,33,-34.2012);
	h_XX_YY_AccGain->Fill(37,34,-34.2012);

	h_XX_YY_AccGain->Fill(38,20,-39.5684);
	h_XX_YY_AccGain->Fill(38,21,-39.5684);
	h_XX_YY_AccGain->Fill(38,22,-39.5684);
	h_XX_YY_AccGain->Fill(38,23,-39.5684);
	h_XX_YY_AccGain->Fill(38,24,-39.5684);
	h_XX_YY_AccGain->Fill(38,25,-39.5684);
	h_XX_YY_AccGain->Fill(38,26,-39.5684);
	h_XX_YY_AccGain->Fill(38,27,-39.5684);
	h_XX_YY_AccGain->Fill(38,28,-39.5684);
	h_XX_YY_AccGain->Fill(38,29,-39.5684);
	h_XX_YY_AccGain->Fill(38,30,-39.5684);
	h_XX_YY_AccGain->Fill(38,31,-39.5684);
	h_XX_YY_AccGain->Fill(38,32,-39.5684);
	h_XX_YY_AccGain->Fill(38,33,-39.5684);
	h_XX_YY_AccGain->Fill(38,34,-39.5684);

	h_XX_YY_AccGain->Fill(39,20,-44.5377);
	h_XX_YY_AccGain->Fill(39,21,-44.5377);
	h_XX_YY_AccGain->Fill(39,22,-44.5377);
	h_XX_YY_AccGain->Fill(39,23,-44.5377);
	h_XX_YY_AccGain->Fill(39,24,-44.5377);
	h_XX_YY_AccGain->Fill(39,25,-44.5377);
	h_XX_YY_AccGain->Fill(39,26,-44.5377);
	h_XX_YY_AccGain->Fill(39,27,-44.5377);
	h_XX_YY_AccGain->Fill(39,28,-44.5377);
	h_XX_YY_AccGain->Fill(39,29,-44.5377);
	h_XX_YY_AccGain->Fill(39,30,-44.5377);
	h_XX_YY_AccGain->Fill(39,31,-44.5377);
	h_XX_YY_AccGain->Fill(39,32,-44.5377);
	h_XX_YY_AccGain->Fill(39,33,-44.5377);
	h_XX_YY_AccGain->Fill(39,34,-44.5377);

	h_XX_YY_AccGain->Fill(40,20,-48.9188);
	h_XX_YY_AccGain->Fill(40,21,-48.9188);
	h_XX_YY_AccGain->Fill(40,22,-48.9188);
	h_XX_YY_AccGain->Fill(40,23,-48.9188);
	h_XX_YY_AccGain->Fill(40,24,-48.9188);
	h_XX_YY_AccGain->Fill(40,25,-48.9188);
	h_XX_YY_AccGain->Fill(40,26,-48.9188);
	h_XX_YY_AccGain->Fill(40,27,-48.9188);
	h_XX_YY_AccGain->Fill(40,28,-48.9188);
	h_XX_YY_AccGain->Fill(40,29,-48.9188);
	h_XX_YY_AccGain->Fill(40,30,-48.9188);
	h_XX_YY_AccGain->Fill(40,31,-48.9188);
	h_XX_YY_AccGain->Fill(40,32,-48.9188);
	h_XX_YY_AccGain->Fill(40,33,-48.9188);
	h_XX_YY_AccGain->Fill(40,34,-48.9188);

	h_XX_YY_AccGain->SetBit(TH1::kNoStats);

	TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
    tex_cms->AddText("CMS Internal");
    tex_cms->SetTextSize(0.035);
    tex_cms->SetFillStyle(0);
    tex_cms->SetBorderSize(0);

    TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
    tex_lumi->AddText("2018 Simulation (13 TeV)");
    tex_lumi->SetTextSize(0.035);
    tex_lumi->SetFillStyle(0);
    tex_lumi->SetBorderSize(0);

    TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
    tex_run->AddText("VBF H#rightarrow#tau#tau");
    tex_run->SetTextColor(0);
    tex_run->SetTextSize(0.04);
    tex_run->SetFillStyle(0);
    tex_run->SetBorderSize(0);

    TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
    tex_cat->AddText("0-jet");
    tex_cat->SetTextColor(0);
    tex_cat->SetTextSize(0.04);
    tex_cat->SetFillStyle(0);
    tex_cat->SetBorderSize(0);

    TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
    tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
    tex_cuts1->SetTextColor(0);
    tex_cuts1->SetTextSize(0.03);
    tex_cuts1->SetFillStyle(0);
    tex_cuts1->SetBorderSize(0);

    TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
    tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
    tex_cuts2->SetTextColor(0);
    tex_cuts2->SetTextSize(0.03);
    tex_cuts2->SetFillStyle(0);
    tex_cuts2->SetBorderSize(0);

    h_XX_YY_AccGain->SetTitle("");
    h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
    h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
    h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
    h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
    h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
    h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
    h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
    h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
    h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
    //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
    gPad->Update();
    //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    //gPad->Update();

    //gStyle->SetPalette(kSandyTerrain);

	h_XX_YY_AccGain->Draw("colz");
	tex_cms->Draw("same");
    tex_lumi->Draw("same");
    tex_run->Draw("same"); tex_cat->Draw("same");
    tex_cuts1->Draw("same");
    tex_cuts2->Draw("same");

    c1->SaveAs("plots/acceptance_gain_0jet_VBF.pdf","pdf");

   

}


void plot_acceptance_0jet_ggF(){

	TCanvas *c1 = new TCanvas("c1","c1",600,650);
	c1->SetRightMargin(0.16);

	TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

    h_XX_YY_AccGain->Fill(32,20,0);
    h_XX_YY_AccGain->Fill(32,21,0);
    h_XX_YY_AccGain->Fill(32,22,0);
    h_XX_YY_AccGain->Fill(32,23,0);
    h_XX_YY_AccGain->Fill(32,24,0);
    h_XX_YY_AccGain->Fill(32,25,0);
    h_XX_YY_AccGain->Fill(32,26,0);
    h_XX_YY_AccGain->Fill(32,27,0);
    h_XX_YY_AccGain->Fill(32,28,0);
    h_XX_YY_AccGain->Fill(32,29,0);
    h_XX_YY_AccGain->Fill(32,30,0);
    h_XX_YY_AccGain->Fill(32,31,0);
    h_XX_YY_AccGain->Fill(32,32,0);
    h_XX_YY_AccGain->Fill(32,33,0);
    h_XX_YY_AccGain->Fill(32,34,0);

    h_XX_YY_AccGain->Fill(33,20,-12.9016);
	h_XX_YY_AccGain->Fill(33,21,-12.9016);
	h_XX_YY_AccGain->Fill(33,22,-12.9016);
	h_XX_YY_AccGain->Fill(33,23,-12.9016);
	h_XX_YY_AccGain->Fill(33,24,-12.9016);
	h_XX_YY_AccGain->Fill(33,25,-12.9016);
    h_XX_YY_AccGain->Fill(33,26,-12.9016);
    h_XX_YY_AccGain->Fill(33,27,-12.9016);
    h_XX_YY_AccGain->Fill(33,28,-12.9016);
    h_XX_YY_AccGain->Fill(33,29,-12.9016);
    h_XX_YY_AccGain->Fill(33,30,-12.9016);
    h_XX_YY_AccGain->Fill(33,31,-12.9016);
	h_XX_YY_AccGain->Fill(33,32,-12.9016);
	h_XX_YY_AccGain->Fill(33,33,-12.9016);
	h_XX_YY_AccGain->Fill(33,34,-12.9016);
	 
	h_XX_YY_AccGain->Fill(34,20,-24.7877);
	h_XX_YY_AccGain->Fill(34,21,-24.7877);
	h_XX_YY_AccGain->Fill(34,22,-24.7877);
	h_XX_YY_AccGain->Fill(34,23,-24.7877);
	h_XX_YY_AccGain->Fill(34,24,-24.7877);
	h_XX_YY_AccGain->Fill(34,25,-24.7877);
	h_XX_YY_AccGain->Fill(34,26,-24.7877);
	h_XX_YY_AccGain->Fill(34,27,-24.7877);
	h_XX_YY_AccGain->Fill(34,28,-24.7877);
	h_XX_YY_AccGain->Fill(34,29,-24.7877);
	h_XX_YY_AccGain->Fill(34,30,-24.7877);
	h_XX_YY_AccGain->Fill(34,31,-24.7877);
    h_XX_YY_AccGain->Fill(34,32,-24.7877);
    h_XX_YY_AccGain->Fill(34,33,-24.7877);
    h_XX_YY_AccGain->Fill(34,34,-24.7877);
     
    h_XX_YY_AccGain->Fill(35,20,-34.5847);
    h_XX_YY_AccGain->Fill(35,21,-34.5847);
    h_XX_YY_AccGain->Fill(35,22,-34.5847);
    h_XX_YY_AccGain->Fill(35,23,-34.5847);
    h_XX_YY_AccGain->Fill(35,24,-34.5847);
    h_XX_YY_AccGain->Fill(35,25,-34.5847);
    h_XX_YY_AccGain->Fill(35,26,-34.5847);
    h_XX_YY_AccGain->Fill(35,27,-34.5847);
    h_XX_YY_AccGain->Fill(35,28,-34.5847);
    h_XX_YY_AccGain->Fill(35,29,-34.5847);
    h_XX_YY_AccGain->Fill(35,30,-34.5847);
    h_XX_YY_AccGain->Fill(35,31,-34.5847);
    h_XX_YY_AccGain->Fill(35,32,-34.5847);
    h_XX_YY_AccGain->Fill(35,33,-34.5847);
    h_XX_YY_AccGain->Fill(35,34,-34.5847);
     
    h_XX_YY_AccGain->Fill(36,20,-42.9166);
    h_XX_YY_AccGain->Fill(36,21,-42.9166);
    h_XX_YY_AccGain->Fill(36,22,-42.9166);
    h_XX_YY_AccGain->Fill(36,23,-42.9166);
    h_XX_YY_AccGain->Fill(36,24,-42.9166);
    h_XX_YY_AccGain->Fill(36,25,-42.9166);
    h_XX_YY_AccGain->Fill(36,26,-42.9166);
    h_XX_YY_AccGain->Fill(36,27,-42.9166);
    h_XX_YY_AccGain->Fill(36,28,-42.9166);
    h_XX_YY_AccGain->Fill(36,29,-42.9166);
    h_XX_YY_AccGain->Fill(36,30,-42.9166);
    h_XX_YY_AccGain->Fill(36,31,-42.9166);
    h_XX_YY_AccGain->Fill(36,32,-42.9166);
    h_XX_YY_AccGain->Fill(36,33,-42.9166);
    h_XX_YY_AccGain->Fill(36,34,-42.9166);
     
    h_XX_YY_AccGain->Fill(37,20,-50.7574);
    h_XX_YY_AccGain->Fill(37,21,-50.7574);
    h_XX_YY_AccGain->Fill(37,22,-50.7574);
    h_XX_YY_AccGain->Fill(37,23,-50.7574);
    h_XX_YY_AccGain->Fill(37,24,-50.7574);
    h_XX_YY_AccGain->Fill(37,25,-50.7574);
    h_XX_YY_AccGain->Fill(37,26,-50.7574);
    h_XX_YY_AccGain->Fill(37,27,-50.7574);
	h_XX_YY_AccGain->Fill(37,28,-50.7574);
	h_XX_YY_AccGain->Fill(37,29,-50.7574);
	h_XX_YY_AccGain->Fill(37,30,-50.7574);
	h_XX_YY_AccGain->Fill(37,31,-50.7574);
	h_XX_YY_AccGain->Fill(37,32,-50.7574);
	h_XX_YY_AccGain->Fill(37,33,-50.7574);
	h_XX_YY_AccGain->Fill(37,34,-50.7574);
	 
	h_XX_YY_AccGain->Fill(38,20,-57.5662);
	h_XX_YY_AccGain->Fill(38,21,-57.5662);
	h_XX_YY_AccGain->Fill(38,22,-57.5662);
	h_XX_YY_AccGain->Fill(38,23,-57.5662);
	h_XX_YY_AccGain->Fill(38,24,-57.5662);
	h_XX_YY_AccGain->Fill(38,25,-57.5662);
	h_XX_YY_AccGain->Fill(38,26,-57.5662);
	h_XX_YY_AccGain->Fill(38,27,-57.5662);
	h_XX_YY_AccGain->Fill(38,28,-57.5662);
	h_XX_YY_AccGain->Fill(38,29,-57.5662);
	h_XX_YY_AccGain->Fill(38,30,-57.5662);
	h_XX_YY_AccGain->Fill(38,31,-57.5662);
	h_XX_YY_AccGain->Fill(38,32,-57.5662);
	h_XX_YY_AccGain->Fill(38,33,-57.5662);
	h_XX_YY_AccGain->Fill(38,34,-57.5662);
	 
	h_XX_YY_AccGain->Fill(39,20,-63.6008);
	h_XX_YY_AccGain->Fill(39,21,-63.6008);
	h_XX_YY_AccGain->Fill(39,22,-63.6008);
	h_XX_YY_AccGain->Fill(39,23,-63.6008);
	h_XX_YY_AccGain->Fill(39,24,-63.6008);
	h_XX_YY_AccGain->Fill(39,25,-63.6008);
	h_XX_YY_AccGain->Fill(39,26,-63.6008);
	h_XX_YY_AccGain->Fill(39,27,-63.6008);
	h_XX_YY_AccGain->Fill(39,28,-63.6008);
	h_XX_YY_AccGain->Fill(39,29,-63.6008);
	h_XX_YY_AccGain->Fill(39,30,-63.6008);
	h_XX_YY_AccGain->Fill(39,31,-63.6008);
	h_XX_YY_AccGain->Fill(39,32,-63.6008);
	h_XX_YY_AccGain->Fill(39,33,-63.6008);
	h_XX_YY_AccGain->Fill(39,34,-63.6008);
	 
	h_XX_YY_AccGain->Fill(40,20,-68.3952);
	h_XX_YY_AccGain->Fill(40,21,-68.3952);
	h_XX_YY_AccGain->Fill(40,22,-68.3952);
	h_XX_YY_AccGain->Fill(40,23,-68.3952);
	h_XX_YY_AccGain->Fill(40,24,-68.3952);
	h_XX_YY_AccGain->Fill(40,25,-68.3952);
	h_XX_YY_AccGain->Fill(40,26,-68.3952);
	h_XX_YY_AccGain->Fill(40,27,-68.3952);
	h_XX_YY_AccGain->Fill(40,28,-68.3952);
	h_XX_YY_AccGain->Fill(40,29,-68.3952);
	h_XX_YY_AccGain->Fill(40,30,-68.3952);
	h_XX_YY_AccGain->Fill(40,31,-68.3952);
	h_XX_YY_AccGain->Fill(40,32,-68.3952);
	h_XX_YY_AccGain->Fill(40,33,-68.3952);
	h_XX_YY_AccGain->Fill(40,34,-68.3952);

	h_XX_YY_AccGain->SetBit(TH1::kNoStats);

	TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
    tex_cms->AddText("CMS Internal");
    tex_cms->SetTextSize(0.035);
    tex_cms->SetFillStyle(0);
    tex_cms->SetBorderSize(0);

    TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
    tex_lumi->AddText("2018 Simulation (13 TeV)");
    tex_lumi->SetTextSize(0.035);
    tex_lumi->SetFillStyle(0);
    tex_lumi->SetBorderSize(0);

    TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
    tex_run->AddText("ggF H#rightarrow#tau#tau");
    tex_run->SetTextColor(0);
    tex_run->SetTextSize(0.04);
    tex_run->SetFillStyle(0);
    tex_run->SetBorderSize(0);

    TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
    tex_cat->AddText("0-jet");
    tex_cat->SetTextColor(0);
    tex_cat->SetTextSize(0.04);
    tex_cat->SetFillStyle(0);
    tex_cat->SetBorderSize(0);

    TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
    tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
    tex_cuts1->SetTextColor(0);
    tex_cuts1->SetTextSize(0.03);
    tex_cuts1->SetFillStyle(0);
    tex_cuts1->SetBorderSize(0);

    TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
    tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
    tex_cuts2->SetTextColor(0);
    tex_cuts2->SetTextSize(0.03);
    tex_cuts2->SetFillStyle(0);
    tex_cuts2->SetBorderSize(0);

    h_XX_YY_AccGain->SetTitle("");
    h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
    h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
    h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
    h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
    h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
    h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
    h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
    h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
    h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
    //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
    gPad->Update();
    //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    //gPad->Update();

    //gStyle->SetPalette(kSandyTerrain);

	h_XX_YY_AccGain->Draw("colz");
	tex_cms->Draw("same");
    tex_lumi->Draw("same");
    tex_run->Draw("same"); tex_cat->Draw("same");
    tex_cuts1->Draw("same");
    tex_cuts2->Draw("same");

    c1->SaveAs("plots/acceptance_gain_0jet_ggF.pdf","pdf");


}


void plot_acceptance_1jet_VBF(){

  TCanvas *c1 = new TCanvas("c1","c1",600,650);
  c1->SetRightMargin(0.16);

  TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

  h_XX_YY_AccGain->Fill(32,20,14.0501);
  h_XX_YY_AccGain->Fill(32,21,12.8668);
  h_XX_YY_AccGain->Fill(32,22,11.4635);
  h_XX_YY_AccGain->Fill(32,23,13.0647);
  h_XX_YY_AccGain->Fill(32,24,15.251);
  h_XX_YY_AccGain->Fill(32,25,15.1938);
  h_XX_YY_AccGain->Fill(32,26,15.0222);
  h_XX_YY_AccGain->Fill(32,27,12.1189);
  h_XX_YY_AccGain->Fill(32,28,9.45762);
  h_XX_YY_AccGain->Fill(32,29,9.76994);
  h_XX_YY_AccGain->Fill(32,30,7.27137);
  h_XX_YY_AccGain->Fill(32,31,6.39599);
  h_XX_YY_AccGain->Fill(32,32,0);
  h_XX_YY_AccGain->Fill(32,33,0);
  h_XX_YY_AccGain->Fill(32,34,0);
  
  h_XX_YY_AccGain->Fill(33,20,23.886);
  h_XX_YY_AccGain->Fill(33,21,21.0883);
  h_XX_YY_AccGain->Fill(33,22,20.1821);
  h_XX_YY_AccGain->Fill(33,23,18.1278);
  h_XX_YY_AccGain->Fill(33,24,21.5106);
  h_XX_YY_AccGain->Fill(33,25,21.2291);
  h_XX_YY_AccGain->Fill(33,26,27.1983);
  h_XX_YY_AccGain->Fill(33,27,23.2525);
  h_XX_YY_AccGain->Fill(33,28,22.1264);
  h_XX_YY_AccGain->Fill(33,29,19.4475);
  h_XX_YY_AccGain->Fill(33,30,14.1952);
  h_XX_YY_AccGain->Fill(33,31,6.97664);
  h_XX_YY_AccGain->Fill(33,32,0);
  h_XX_YY_AccGain->Fill(33,33,-7.70246);
  h_XX_YY_AccGain->Fill(33,34,-7.70246);

  h_XX_YY_AccGain->Fill(34,20,22.1044);
  h_XX_YY_AccGain->Fill(34,21,21.5546);
  h_XX_YY_AccGain->Fill(34,22,19.166);
  h_XX_YY_AccGain->Fill(34,23,18.3654);
  h_XX_YY_AccGain->Fill(34,24,21.2554);
  h_XX_YY_AccGain->Fill(34,25,22.5003);
  h_XX_YY_AccGain->Fill(34,26,31.6544);
  h_XX_YY_AccGain->Fill(34,27,27.018);
  h_XX_YY_AccGain->Fill(34,28,23.7804);
  h_XX_YY_AccGain->Fill(34,29,20.0238);
  h_XX_YY_AccGain->Fill(34,30,14.2392);
  h_XX_YY_AccGain->Fill(34,31,6.99424);
  h_XX_YY_AccGain->Fill(34,32,0);
  h_XX_YY_AccGain->Fill(34,33,-7.70246);
  h_XX_YY_AccGain->Fill(34,34,-15.1894);
   
  h_XX_YY_AccGain->Fill(35,20,23.82);
  h_XX_YY_AccGain->Fill(35,21,21.7525);
  h_XX_YY_AccGain->Fill(35,22,20.7936);
  h_XX_YY_AccGain->Fill(35,23,19.4695);
  h_XX_YY_AccGain->Fill(35,24,21.7261);
  h_XX_YY_AccGain->Fill(35,25,26.3933);
  h_XX_YY_AccGain->Fill(35,26,34.1266);
  h_XX_YY_AccGain->Fill(35,27,30.5019);
  h_XX_YY_AccGain->Fill(35,28,25.6235);
  h_XX_YY_AccGain->Fill(35,29,21.493);
  h_XX_YY_AccGain->Fill(35,30,14.9342);
  h_XX_YY_AccGain->Fill(35,31,7.05142);
  h_XX_YY_AccGain->Fill(35,32,-0.00439889);
  h_XX_YY_AccGain->Fill(35,33,-7.70686);
  h_XX_YY_AccGain->Fill(35,34,-15.1938);

  h_XX_YY_AccGain->Fill(36,20,23.2393);
  h_XX_YY_AccGain->Fill(36,21,19.1792);
  h_XX_YY_AccGain->Fill(36,22,18.4006);
  h_XX_YY_AccGain->Fill(36,23,18.6513);
  h_XX_YY_AccGain->Fill(36,24,18.3038);
  h_XX_YY_AccGain->Fill(36,25,23.6176);
  h_XX_YY_AccGain->Fill(36,26,34.065);
  h_XX_YY_AccGain->Fill(36,27,30.4711);
  h_XX_YY_AccGain->Fill(36,28,25.43);
  h_XX_YY_AccGain->Fill(36,29,20.6792);
  h_XX_YY_AccGain->Fill(36,30,14.38);
  h_XX_YY_AccGain->Fill(36,31,6.70391);
  h_XX_YY_AccGain->Fill(36,32,-0.00439889);
  h_XX_YY_AccGain->Fill(36,33,-7.70686);
  h_XX_YY_AccGain->Fill(36,34,-15.1938);
   
  h_XX_YY_AccGain->Fill(37,20,19.9138);
  h_XX_YY_AccGain->Fill(37,21,17.8595);
  h_XX_YY_AccGain->Fill(37,22,16.9973);
  h_XX_YY_AccGain->Fill(37,23,15.6381);
  h_XX_YY_AccGain->Fill(37,24,17.1029);
  h_XX_YY_AccGain->Fill(37,25,23.1954);
  h_XX_YY_AccGain->Fill(37,26,34.3158);
  h_XX_YY_AccGain->Fill(37,27,30.7307);
  h_XX_YY_AccGain->Fill(37,28,24.4402);
  h_XX_YY_AccGain->Fill(37,29,21.0927);
  h_XX_YY_AccGain->Fill(37,30,13.9401);
  h_XX_YY_AccGain->Fill(37,31,7.09981);
  h_XX_YY_AccGain->Fill(37,32,-0.00439889);
  h_XX_YY_AccGain->Fill(37,33,-7.70686);
  h_XX_YY_AccGain->Fill(37,34,-15.1938);
   
  h_XX_YY_AccGain->Fill(38,20,18.9768);
  h_XX_YY_AccGain->Fill(38,21,18.6469);
  h_XX_YY_AccGain->Fill(38,22,17.6879);
  h_XX_YY_AccGain->Fill(38,23,16.4651);
  h_XX_YY_AccGain->Fill(38,24,18.0135);
  h_XX_YY_AccGain->Fill(38,25,24.9285);
  h_XX_YY_AccGain->Fill(38,26,35.0108);
  h_XX_YY_AccGain->Fill(38,27,31.4565);
  h_XX_YY_AccGain->Fill(38,28,25.0385);
  h_XX_YY_AccGain->Fill(38,29,21.7261);
  h_XX_YY_AccGain->Fill(38,30,14.5119);
  h_XX_YY_AccGain->Fill(38,31,6.92825);
  h_XX_YY_AccGain->Fill(38,32,-0.00439889);
  h_XX_YY_AccGain->Fill(38,33,-7.70686);
  h_XX_YY_AccGain->Fill(38,34,-15.1938);
   
  h_XX_YY_AccGain->Fill(39,20,20.5824);
  h_XX_YY_AccGain->Fill(39,21,20.0809);
  h_XX_YY_AccGain->Fill(39,22,17.1997);
  h_XX_YY_AccGain->Fill(39,23,16.056);
  h_XX_YY_AccGain->Fill(39,24,15.8712);
  h_XX_YY_AccGain->Fill(39,25,25.3772);
  h_XX_YY_AccGain->Fill(39,26,34.0386);
  h_XX_YY_AccGain->Fill(39,27,32.2791);
  h_XX_YY_AccGain->Fill(39,28,25.9535);
  h_XX_YY_AccGain->Fill(39,29,21.3918);
  h_XX_YY_AccGain->Fill(39,30,14.292);
  h_XX_YY_AccGain->Fill(39,31,6.78749);
  h_XX_YY_AccGain->Fill(39,32,-0.00439889);
  h_XX_YY_AccGain->Fill(39,33,-7.70686);
  h_XX_YY_AccGain->Fill(39,34,-15.1938);
   
  h_XX_YY_AccGain->Fill(40,20,20.4021);
  h_XX_YY_AccGain->Fill(40,21,17.8771);
  h_XX_YY_AccGain->Fill(40,22,17.2964);
  h_XX_YY_AccGain->Fill(40,23,14.0061);
  h_XX_YY_AccGain->Fill(40,24,16.0384);
  h_XX_YY_AccGain->Fill(40,25,28.2585);
  h_XX_YY_AccGain->Fill(40,26,35.1735);
  h_XX_YY_AccGain->Fill(40,27,31.672);
  h_XX_YY_AccGain->Fill(40,28,27.0092);
  h_XX_YY_AccGain->Fill(40,29,21.0443);
  h_XX_YY_AccGain->Fill(40,30,14.0501);
  h_XX_YY_AccGain->Fill(40,31,6.69071);
  h_XX_YY_AccGain->Fill(40,32,-0.00439889);
  h_XX_YY_AccGain->Fill(40,33,-7.70686);
  h_XX_YY_AccGain->Fill(40,34,-15.1938);

  h_XX_YY_AccGain->SetBit(TH1::kNoStats);

  TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
  tex_cms->AddText("CMS Internal");
  tex_cms->SetTextSize(0.035);
  tex_cms->SetFillStyle(0);
  tex_cms->SetBorderSize(0);

  TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
  tex_lumi->AddText("2018 Simulation (13 TeV)");
  tex_lumi->SetTextSize(0.035);
  tex_lumi->SetFillStyle(0);
  tex_lumi->SetBorderSize(0);

  TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
  tex_run->AddText("VBF H#rightarrow#tau#tau");
  tex_run->SetTextColor(0);
  tex_run->SetTextSize(0.04);
  tex_run->SetFillStyle(0);
  tex_run->SetBorderSize(0);

  TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
  tex_cat->AddText("1-jet");
  tex_cat->SetTextColor(0);
  tex_cat->SetTextSize(0.04);
  tex_cat->SetFillStyle(0);
  tex_cat->SetBorderSize(0);

  TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
  tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
  tex_cuts1->SetTextColor(0);
  tex_cuts1->SetTextSize(0.03);
  tex_cuts1->SetFillStyle(0);
  tex_cuts1->SetBorderSize(0);

  TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
  tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
  tex_cuts2->SetTextColor(0);
  tex_cuts2->SetTextSize(0.03);
  tex_cuts2->SetFillStyle(0);
  tex_cuts2->SetBorderSize(0);

  h_XX_YY_AccGain->SetTitle("");
  h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
  h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
  h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
  h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
  h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
  h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
  h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
  h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
  h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
  h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
  h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
  //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
  gPad->Update();
  //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
  //gPad->Update();

  //gStyle->SetPalette(kSandyTerrain);

  h_XX_YY_AccGain->Draw("colz");
  tex_cms->Draw("same");
  tex_lumi->Draw("same");
  tex_run->Draw("same"); tex_cat->Draw("same");
  tex_cuts1->Draw("same");
  tex_cuts2->Draw("same");

  c1->SaveAs("plots/acceptance_gain_1jet_VBF.pdf","pdf");

  cout<<h_XX_YY_AccGain->GetMaximum()<<endl;

}


void plot_acceptance_1jet_ggF(){

  TCanvas *c1 = new TCanvas("c1","c1",600,650);
  c1->SetRightMargin(0.16);

  TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

  h_XX_YY_AccGain->Fill(32,20,7.9477);
  h_XX_YY_AccGain->Fill(32,21,7.28662);
  h_XX_YY_AccGain->Fill(32,22,6.56677);
  h_XX_YY_AccGain->Fill(32,23,7.43352);
  h_XX_YY_AccGain->Fill(32,24,8.38842);
  h_XX_YY_AccGain->Fill(32,25,7.77141);
  h_XX_YY_AccGain->Fill(32,26,7.36007);
  h_XX_YY_AccGain->Fill(32,27,5.8763);
  h_XX_YY_AccGain->Fill(32,28,4.75981);
  h_XX_YY_AccGain->Fill(32,29,4.9361);
  h_XX_YY_AccGain->Fill(32,30,3.79022);
  h_XX_YY_AccGain->Fill(32,31,3.71676);
  h_XX_YY_AccGain->Fill(32,32,0);
  h_XX_YY_AccGain->Fill(32,33,0);
  h_XX_YY_AccGain->Fill(32,34,0);
  
  h_XX_YY_AccGain->Fill(33,20,6.50801);
  h_XX_YY_AccGain->Fill(33,21,5.083);
  h_XX_YY_AccGain->Fill(33,22,4.62759);
  h_XX_YY_AccGain->Fill(33,23,3.52578);
  h_XX_YY_AccGain->Fill(33,24,5.21522);
  h_XX_YY_AccGain->Fill(33,25,4.96548);
  h_XX_YY_AccGain->Fill(33,26,8.75569);
  h_XX_YY_AccGain->Fill(33,27,6.71368);
  h_XX_YY_AccGain->Fill(33,28,7.37476);
  h_XX_YY_AccGain->Fill(33,29,6.86058);
  h_XX_YY_AccGain->Fill(33,30,6.34641);
  h_XX_YY_AccGain->Fill(33,31,2.24769);
  h_XX_YY_AccGain->Fill(33,32,-0.19098);
  h_XX_YY_AccGain->Fill(33,33,-10.4157);
  h_XX_YY_AccGain->Fill(33,34,-10.4157);
  
  h_XX_YY_AccGain->Fill(34,20,-0.146908);
  h_XX_YY_AccGain->Fill(34,21,-0.396651);
  h_XX_YY_AccGain->Fill(34,22,-1.64537);
  h_XX_YY_AccGain->Fill(34,23,-2.01263);
  h_XX_YY_AccGain->Fill(34,24,-0.440723);
  h_XX_YY_AccGain->Fill(34,25,0.822683);
  h_XX_YY_AccGain->Fill(34,26,7.44822);
  h_XX_YY_AccGain->Fill(34,27,5.06831);
  h_XX_YY_AccGain->Fill(34,28,5.36213);
  h_XX_YY_AccGain->Fill(34,29,5.14177);
  h_XX_YY_AccGain->Fill(34,30,4.4513);
  h_XX_YY_AccGain->Fill(34,31,0.998972);
  h_XX_YY_AccGain->Fill(34,32,-0.308506);
  h_XX_YY_AccGain->Fill(34,33,-10.5333);
  h_XX_YY_AccGain->Fill(34,34,-20.1557);
  
  h_XX_YY_AccGain->Fill(35,20,-3.48171);
  h_XX_YY_AccGain->Fill(35,21,-4.36316);
  h_XX_YY_AccGain->Fill(35,22,-4.84795);
  h_XX_YY_AccGain->Fill(35,23,-5.59718);
  h_XX_YY_AccGain->Fill(35,24,-4.14279);
  h_XX_YY_AccGain->Fill(35,25,-0.396651);
  h_XX_YY_AccGain->Fill(35,26,5.99383);
  h_XX_YY_AccGain->Fill(35,27,5.75878);
  h_XX_YY_AccGain->Fill(35,28,5.27398);
  h_XX_YY_AccGain->Fill(35,29,6.53739);
  h_XX_YY_AccGain->Fill(35,30,4.86264);
  h_XX_YY_AccGain->Fill(35,31,0.19098);
  h_XX_YY_AccGain->Fill(35,32,-0.426032);
  h_XX_YY_AccGain->Fill(35,33,-10.6508);
  h_XX_YY_AccGain->Fill(35,34,-20.2732);
  
  h_XX_YY_AccGain->Fill(36,20,-6.93404);
  h_XX_YY_AccGain->Fill(36,21,-8.93198);
  h_XX_YY_AccGain->Fill(36,22,-9.35801);
  h_XX_YY_AccGain->Fill(36,23,-8.99074);
  h_XX_YY_AccGain->Fill(36,24,-9.13765);
  h_XX_YY_AccGain->Fill(36,25,-5.12708);
  h_XX_YY_AccGain->Fill(36,26,3.67269);
  h_XX_YY_AccGain->Fill(36,27,3.8196);
  h_XX_YY_AccGain->Fill(36,28,4.05465);
  h_XX_YY_AccGain->Fill(36,29,3.92243);
  h_XX_YY_AccGain->Fill(36,30,2.71779);
  h_XX_YY_AccGain->Fill(36,31,-1.425);
  h_XX_YY_AccGain->Fill(36,32,-0.514177);
  h_XX_YY_AccGain->Fill(36,33,-10.7389);
  h_XX_YY_AccGain->Fill(36,34,-20.3614);
  
  h_XX_YY_AccGain->Fill(37,20,-12.0317);
  h_XX_YY_AccGain->Fill(37,21,-13.0013);
  h_XX_YY_AccGain->Fill(37,22,-13.5008);
  h_XX_YY_AccGain->Fill(37,23,-13.8387);
  h_XX_YY_AccGain->Fill(37,24,-12.6194);
  h_XX_YY_AccGain->Fill(37,25,-8.49126);
  h_XX_YY_AccGain->Fill(37,26,1.89511);
  h_XX_YY_AccGain->Fill(37,27,2.48274);
  h_XX_YY_AccGain->Fill(37,28,0.998972);
  h_XX_YY_AccGain->Fill(37,29,3.29073);
  h_XX_YY_AccGain->Fill(37,30,0.837373);
  h_XX_YY_AccGain->Fill(37,31,-0.484795);
  h_XX_YY_AccGain->Fill(37,32,-0.602321);
  h_XX_YY_AccGain->Fill(37,33,-10.8271);
  h_XX_YY_AccGain->Fill(37,34,-20.4495);
   
  h_XX_YY_AccGain->Fill(38,20,-15.7779);
  h_XX_YY_AccGain->Fill(38,21,-15.9395);
  h_XX_YY_AccGain->Fill(38,22,-16.0717);
  h_XX_YY_AccGain->Fill(38,23,-16.4977);
  h_XX_YY_AccGain->Fill(38,24,-15.014);
  h_XX_YY_AccGain->Fill(38,25,-9.81343);
  h_XX_YY_AccGain->Fill(38,26,0.910827);
  h_XX_YY_AccGain->Fill(38,27,1.73351);
  h_XX_YY_AccGain->Fill(38,28,0.631703);
  h_XX_YY_AccGain->Fill(38,29,4.17218);
  h_XX_YY_AccGain->Fill(38,30,2.01263);
  h_XX_YY_AccGain->Fill(38,31,-1.49846);
  h_XX_YY_AccGain->Fill(38,32,-0.661084);
  h_XX_YY_AccGain->Fill(38,33,-10.8859);
  h_XX_YY_AccGain->Fill(38,34,-20.5083);
   
  h_XX_YY_AccGain->Fill(39,20,-17.482);
  h_XX_YY_AccGain->Fill(39,21,-17.3057);
  h_XX_YY_AccGain->Fill(39,22,-18.672);
  h_XX_YY_AccGain->Fill(39,23,-19.0098);
  h_XX_YY_AccGain->Fill(39,24,-18.5838);
  h_XX_YY_AccGain->Fill(39,25,-11.4588);
  h_XX_YY_AccGain->Fill(39,26,-1.68944);
  h_XX_YY_AccGain->Fill(39,27,2.11547);
  h_XX_YY_AccGain->Fill(39,28,1.05773);
  h_XX_YY_AccGain->Fill(39,29,2.43867);
  h_XX_YY_AccGain->Fill(39,30,0.675775);
  h_XX_YY_AccGain->Fill(39,31,-2.3799);
  h_XX_YY_AccGain->Fill(39,32,-0.749229);
  h_XX_YY_AccGain->Fill(39,33,-10.974);
  h_XX_YY_AccGain->Fill(39,34,-20.5964);

  h_XX_YY_AccGain->Fill(40,20,-19.098);
  h_XX_YY_AccGain->Fill(40,21,-20.1557);
  h_XX_YY_AccGain->Fill(40,22,-20.3173);
  h_XX_YY_AccGain->Fill(40,23,-21.7864);
  h_XX_YY_AccGain->Fill(40,24,-20.0529);
  h_XX_YY_AccGain->Fill(40,25,-10.6067);
  h_XX_YY_AccGain->Fill(40,26,-1.29279);
  h_XX_YY_AccGain->Fill(40,27,0.411341);
  h_XX_YY_AccGain->Fill(40,28,2.61496);
  h_XX_YY_AccGain->Fill(40,29,1.24871);
  h_XX_YY_AccGain->Fill(40,30,-0.337887);
  h_XX_YY_AccGain->Fill(40,31,-3.08506);
  h_XX_YY_AccGain->Fill(40,32,-0.822683);
  h_XX_YY_AccGain->Fill(40,33,-11.0475);
  h_XX_YY_AccGain->Fill(40,34,-20.6699);

  h_XX_YY_AccGain->SetBit(TH1::kNoStats);

  TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
  tex_cms->AddText("CMS Internal");
  tex_cms->SetTextSize(0.035);
  tex_cms->SetFillStyle(0);
  tex_cms->SetBorderSize(0);

  TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
  tex_lumi->AddText("2018 Simulation (13 TeV)");
  tex_lumi->SetTextSize(0.035);
  tex_lumi->SetFillStyle(0);
  tex_lumi->SetBorderSize(0);

  TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
  tex_run->AddText("ggF H#rightarrow#tau#tau");
  tex_run->SetTextColor(0);
  tex_run->SetTextSize(0.04);
  tex_run->SetFillStyle(0);
  tex_run->SetBorderSize(0);

  TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
  tex_cat->AddText("1-jet");
  tex_cat->SetTextColor(0);
  tex_cat->SetTextSize(0.04);
  tex_cat->SetFillStyle(0);
  tex_cat->SetBorderSize(0);

  TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
  tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
  tex_cuts1->SetTextColor(0);
  tex_cuts1->SetTextSize(0.03);
  tex_cuts1->SetFillStyle(0);
  tex_cuts1->SetBorderSize(0);

  TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
  tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
  tex_cuts2->SetTextColor(0);
  tex_cuts2->SetTextSize(0.03);
  tex_cuts2->SetFillStyle(0);
  tex_cuts2->SetBorderSize(0);

  h_XX_YY_AccGain->SetTitle("");
  h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
  h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
  h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
  h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
  h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
  h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
  h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
  h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
  h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
  h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
  h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
  //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
  gPad->Update();
  //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
  //gPad->Update();

  //gStyle->SetPalette(kSandyTerrain);

  h_XX_YY_AccGain->Draw("colz");
  tex_cms->Draw("same");
  tex_lumi->Draw("same");
  tex_run->Draw("same"); tex_cat->Draw("same");
  tex_cuts1->Draw("same");
  tex_cuts2->Draw("same");

  c1->SaveAs("plots/acceptance_gain_1jet_ggF.pdf","pdf");
  cout<<h_XX_YY_AccGain->GetMaximum()<<endl;
}


void plot_acceptance_2jet_VBF(){

  TCanvas *c1 = new TCanvas("c1","c1",600,650);
  c1->SetRightMargin(0.16);

  TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

  h_XX_YY_AccGain->Fill(32,20,20.5551);
  h_XX_YY_AccGain->Fill(32,21,19.1464);
  h_XX_YY_AccGain->Fill(32,22,17.4758);
  h_XX_YY_AccGain->Fill(32,23,20.0838);
  h_XX_YY_AccGain->Fill(32,24,23.6345);
  h_XX_YY_AccGain->Fill(32,25,24.0534);
  h_XX_YY_AccGain->Fill(32,26,24.2734);
  h_XX_YY_AccGain->Fill(32,27,20.817);
  h_XX_YY_AccGain->Fill(32,28,17.6486);
  h_XX_YY_AccGain->Fill(32,29,19.4239);
  h_XX_YY_AccGain->Fill(32,30,17.2139);
  h_XX_YY_AccGain->Fill(32,31,20.4975);
  h_XX_YY_AccGain->Fill(32,32,19.0469);
  h_XX_YY_AccGain->Fill(32,33,17.1982);
  h_XX_YY_AccGain->Fill(32,34,15.3181);
  
  h_XX_YY_AccGain->Fill(33,20,36.0566);
  h_XX_YY_AccGain->Fill(33,21,32.7258);
  h_XX_YY_AccGain->Fill(33,22,31.8356);
  h_XX_YY_AccGain->Fill(33,23,29.5208);
  h_XX_YY_AccGain->Fill(33,24,34.5693);
  h_XX_YY_AccGain->Fill(33,25,34.8311);
  h_XX_YY_AccGain->Fill(33,26,43.5192);
  h_XX_YY_AccGain->Fill(33,27,39.1778);
  h_XX_YY_AccGain->Fill(33,28,39.0678);
  h_XX_YY_AccGain->Fill(33,29,37.0621);
  h_XX_YY_AccGain->Fill(33,30,32.1236);
  h_XX_YY_AccGain->Fill(33,31,24.3205);
  h_XX_YY_AccGain->Fill(33,32,19.0469);
  h_XX_YY_AccGain->Fill(33,33,9.87693);
  h_XX_YY_AccGain->Fill(33,34,7.99686);
  
  h_XX_YY_AccGain->Fill(34,20,35.8942);
  h_XX_YY_AccGain->Fill(34,21,35.5067);
  h_XX_YY_AccGain->Fill(34,22,32.8044);
  h_XX_YY_AccGain->Fill(34,23,32.1079);
  h_XX_YY_AccGain->Fill(34,24,36.3079);
  h_XX_YY_AccGain->Fill(34,25,38.5546);
  h_XX_YY_AccGain->Fill(34,26,51.0814);
  h_XX_YY_AccGain->Fill(34,27,45.9649);
  h_XX_YY_AccGain->Fill(34,28,42.8856);
  h_XX_YY_AccGain->Fill(34,29,39.2197);
  h_XX_YY_AccGain->Fill(34,30,33.3019);
  h_XX_YY_AccGain->Fill(34,31,25.5093);
  h_XX_YY_AccGain->Fill(34,32,19.0469);
  h_XX_YY_AccGain->Fill(34,33,9.87693);
  h_XX_YY_AccGain->Fill(34,34,0.963603);
   
  h_XX_YY_AccGain->Fill(35,20,39.6596);
  h_XX_YY_AccGain->Fill(35,21,37.3291);
  h_XX_YY_AccGain->Fill(35,22,36.4127);
  h_XX_YY_AccGain->Fill(35,23,35.0458);
  h_XX_YY_AccGain->Fill(35,24,38.4184);
  h_XX_YY_AccGain->Fill(35,25,44.7971);
  h_XX_YY_AccGain->Fill(35,26,55.4019);
  h_XX_YY_AccGain->Fill(35,27,51.5999);
  h_XX_YY_AccGain->Fill(35,28,46.3263);
  h_XX_YY_AccGain->Fill(35,29,42.2938);
  h_XX_YY_AccGain->Fill(35,30,34.9882);
  h_XX_YY_AccGain->Fill(35,31,26.1639);
  h_XX_YY_AccGain->Fill(35,32,19.0469);
  h_XX_YY_AccGain->Fill(35,33,9.87693);
  h_XX_YY_AccGain->Fill(35,34,0.963603);
  
  h_XX_YY_AccGain->Fill(36,20,40.4085);
  h_XX_YY_AccGain->Fill(36,21,35.5748);
  h_XX_YY_AccGain->Fill(36,22,34.8416);
  h_XX_YY_AccGain->Fill(36,23,35.47);
  h_XX_YY_AccGain->Fill(36,24,35.4491);
  h_XX_YY_AccGain->Fill(36,25,42.4509);
  h_XX_YY_AccGain->Fill(36,26,56.2294);
  h_XX_YY_AccGain->Fill(36,27,52.4378);
  h_XX_YY_AccGain->Fill(36,28,46.8919);
  h_XX_YY_AccGain->Fill(36,29,41.7963);
  h_XX_YY_AccGain->Fill(36,30,34.7159);
  h_XX_YY_AccGain->Fill(36,31,26.0382);
  h_XX_YY_AccGain->Fill(36,32,19.0469);
  h_XX_YY_AccGain->Fill(36,33,9.87693);
  h_XX_YY_AccGain->Fill(36,34,0.963603);
   
  h_XX_YY_AccGain->Fill(37,20,37.3134);
  h_XX_YY_AccGain->Fill(37,21,34.9568);
  h_XX_YY_AccGain->Fill(37,22,34.0927);
  h_XX_YY_AccGain->Fill(37,23,32.6997);
  h_XX_YY_AccGain->Fill(37,24,34.8835);
  h_XX_YY_AccGain->Fill(37,25,42.7337);
  h_XX_YY_AccGain->Fill(37,26,57.1825);
  h_XX_YY_AccGain->Fill(37,27,53.3595);
  h_XX_YY_AccGain->Fill(37,28,46.1377);
  h_XX_YY_AccGain->Fill(37,29,42.6866);
  h_XX_YY_AccGain->Fill(37,30,34.4593);
  h_XX_YY_AccGain->Fill(37,31,26.8866);
  h_XX_YY_AccGain->Fill(37,32,19.0469);
  h_XX_YY_AccGain->Fill(37,33,9.87693);
  h_XX_YY_AccGain->Fill(37,34,0.963603);
   
  h_XX_YY_AccGain->Fill(38,20,37.1197);
  h_XX_YY_AccGain->Fill(38,21,36.8683);
  h_XX_YY_AccGain->Fill(38,22,35.9309);
  h_XX_YY_AccGain->Fill(38,23,34.6531);
  h_XX_YY_AccGain->Fill(38,24,36.8421);
  h_XX_YY_AccGain->Fill(38,25,45.6559);
  h_XX_YY_AccGain->Fill(38,26,58.6541);
  h_XX_YY_AccGain->Fill(38,27,54.7735);
  h_XX_YY_AccGain->Fill(38,28,47.3265);
  h_XX_YY_AccGain->Fill(38,29,43.8178);
  h_XX_YY_AccGain->Fill(38,30,35.5538);
  h_XX_YY_AccGain->Fill(38,31,26.8133);
  h_XX_YY_AccGain->Fill(38,32,19.0469);
  h_XX_YY_AccGain->Fill(38,33,9.87693);
  h_XX_YY_AccGain->Fill(38,34,0.963603);
   
  h_XX_YY_AccGain->Fill(39,20,39.8795);
  h_XX_YY_AccGain->Fill(39,21,39.4501);
  h_XX_YY_AccGain->Fill(39,22,36.1089);
  h_XX_YY_AccGain->Fill(39,23,34.9097);
  h_XX_YY_AccGain->Fill(39,24,34.9149);
  h_XX_YY_AccGain->Fill(39,25,46.829);
  h_XX_YY_AccGain->Fill(39,26,57.9104);
  h_XX_YY_AccGain->Fill(39,27,56.1665);
  h_XX_YY_AccGain->Fill(39,28,48.8034);
  h_XX_YY_AccGain->Fill(39,29,43.6187);
  h_XX_YY_AccGain->Fill(39,30,35.4386);
  h_XX_YY_AccGain->Fill(39,31,26.7505);
  h_XX_YY_AccGain->Fill(39,32,19.0469);
  h_XX_YY_AccGain->Fill(39,33,9.87693);
  h_XX_YY_AccGain->Fill(39,34,0.963603);
   
  h_XX_YY_AccGain->Fill(40,20,40.419);
  h_XX_YY_AccGain->Fill(40,21,37.481);
  h_XX_YY_AccGain->Fill(40,22,36.9207);
  h_XX_YY_AccGain->Fill(40,23,33.0872);
  h_XX_YY_AccGain->Fill(40,24,35.7319);
  h_XX_YY_AccGain->Fill(40,25,50.9086);
  h_XX_YY_AccGain->Fill(40,26,59.6963);
  h_XX_YY_AccGain->Fill(40,27,55.7319);
  h_XX_YY_AccGain->Fill(40,28,50.4111);
  h_XX_YY_AccGain->Fill(40,29,43.404);
  h_XX_YY_AccGain->Fill(40,30,35.3129);
  h_XX_YY_AccGain->Fill(40,31,26.7033);
  h_XX_YY_AccGain->Fill(40,32,19.0469);
  h_XX_YY_AccGain->Fill(40,33,9.87693);
  h_XX_YY_AccGain->Fill(40,34,0.963603);

  h_XX_YY_AccGain->SetBit(TH1::kNoStats);

  TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
  tex_cms->AddText("CMS Internal");
  tex_cms->SetTextSize(0.035);
  tex_cms->SetFillStyle(0);
  tex_cms->SetBorderSize(0);

  TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
  tex_lumi->AddText("2018 Simulation (13 TeV)");
  tex_lumi->SetTextSize(0.035);
  tex_lumi->SetFillStyle(0);
  tex_lumi->SetBorderSize(0);

  TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
  tex_run->AddText("VBF H#rightarrow#tau#tau");
  tex_run->SetTextColor(0);
  tex_run->SetTextSize(0.04);
  tex_run->SetFillStyle(0);
  tex_run->SetBorderSize(0);

  TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
  tex_cat->AddText("2-jet");
  tex_cat->SetTextColor(0);
  tex_cat->SetTextSize(0.04);
  tex_cat->SetFillStyle(0);
  tex_cat->SetBorderSize(0);

  TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
  tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
  tex_cuts1->SetTextColor(0);
  tex_cuts1->SetTextSize(0.03);
  tex_cuts1->SetFillStyle(0);
  tex_cuts1->SetBorderSize(0);

  TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
  tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
  tex_cuts2->SetTextColor(0);
  tex_cuts2->SetTextSize(0.03);
  tex_cuts2->SetFillStyle(0);
  tex_cuts2->SetBorderSize(0);

  h_XX_YY_AccGain->SetTitle("");
  h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
  h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
  h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
  h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
  h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
  h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
  h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
  h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
  h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
  h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
  h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
  //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
  gPad->Update();
  //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
  //gPad->Update();

  //gStyle->SetPalette(kSandyTerrain);

  h_XX_YY_AccGain->Draw("colz");
  tex_cms->Draw("same");
  tex_lumi->Draw("same");
  tex_run->Draw("same"); tex_cat->Draw("same");
  tex_cuts1->Draw("same");
  tex_cuts2->Draw("same");

  c1->SaveAs("plots/acceptance_gain_2jet_VBF.pdf","pdf");

  cout<<h_XX_YY_AccGain->GetMaximum()<<endl;

}



void plot_acceptance_2jet_ggF(){

  TCanvas *c1 = new TCanvas("c1","c1",600,650);
  c1->SetRightMargin(0.16);

  TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

  h_XX_YY_AccGain->Fill(32,20,28.3308);
  h_XX_YY_AccGain->Fill(32,21,26.9774);
  h_XX_YY_AccGain->Fill(32,22,25.5038);
  h_XX_YY_AccGain->Fill(32,23,29.3534);
  h_XX_YY_AccGain->Fill(32,24,33.985);
  h_XX_YY_AccGain->Fill(32,25,34.015);
  h_XX_YY_AccGain->Fill(32,26,35.0376);
  h_XX_YY_AccGain->Fill(32,27,32);
  h_XX_YY_AccGain->Fill(32,28,29.7143);
  h_XX_YY_AccGain->Fill(32,29,34.1053);
  h_XX_YY_AccGain->Fill(32,30,33.7744);
  h_XX_YY_AccGain->Fill(32,31,50.6165);
  h_XX_YY_AccGain->Fill(32,32,61.835);
  h_XX_YY_AccGain->Fill(32,33,68.5714);
  h_XX_YY_AccGain->Fill(32,34,76.2105);
  
  h_XX_YY_AccGain->Fill(33,20,44.8722);
  h_XX_YY_AccGain->Fill(33,21,41.985);
  h_XX_YY_AccGain->Fill(33,22,41.9549);
  h_XX_YY_AccGain->Fill(33,23,40);
  h_XX_YY_AccGain->Fill(33,24,46.0752);
  h_XX_YY_AccGain->Fill(33,25,47.3684);
  h_XX_YY_AccGain->Fill(33,26,60.2105);
  h_XX_YY_AccGain->Fill(33,27,57.2932);
  h_XX_YY_AccGain->Fill(33,28,63.8195);
  h_XX_YY_AccGain->Fill(33,29,68.8722);
  h_XX_YY_AccGain->Fill(33,30,76);
  h_XX_YY_AccGain->Fill(33,31,74.4361);
  h_XX_YY_AccGain->Fill(33,32,77.835);
  h_XX_YY_AccGain->Fill(33,33,81.0827);
  h_XX_YY_AccGain->Fill(33,34,68.7218);
  
  h_XX_YY_AccGain->Fill(34,20,44.3008);
  h_XX_YY_AccGain->Fill(34,21,44.2707);
  h_XX_YY_AccGain->Fill(34,22,42.0451);
  h_XX_YY_AccGain->Fill(34,23,41.985);
  h_XX_YY_AccGain->Fill(34,24,47.5789);
  h_XX_YY_AccGain->Fill(34,25,52.0902);
  h_XX_YY_AccGain->Fill(34,26,72);
  h_XX_YY_AccGain->Fill(34,27,68.7218);
  h_XX_YY_AccGain->Fill(34,28,73.2932);
  h_XX_YY_AccGain->Fill(34,29,77.6241);
  h_XX_YY_AccGain->Fill(34,30,82.8271);
  h_XX_YY_AccGain->Fill(34,31,82.5865);
  h_XX_YY_AccGain->Fill(34,32,82.835);
  h_XX_YY_AccGain->Fill(34,33,81.0827);
  h_XX_YY_AccGain->Fill(34,34,61.4737);
  
  h_XX_YY_AccGain->Fill(35,20,47.5188);
  h_XX_YY_AccGain->Fill(35,21,46.1353);
  h_XX_YY_AccGain->Fill(35,22,45.9549);
  h_XX_YY_AccGain->Fill(35,23,45.3233);
  h_XX_YY_AccGain->Fill(35,24,50.015);
  h_XX_YY_AccGain->Fill(35,25,60.4211);
  h_XX_YY_AccGain->Fill(35,26,79.3985);
  h_XX_YY_AccGain->Fill(35,27,81.4436);
  h_XX_YY_AccGain->Fill(35,28,83.2782);
  h_XX_YY_AccGain->Fill(35,29,91.0075);
  h_XX_YY_AccGain->Fill(35,30,92.6617);
  h_XX_YY_AccGain->Fill(35,31,87.3985);
  h_XX_YY_AccGain->Fill(35,32,83.835);
  h_XX_YY_AccGain->Fill(35,33,81.0827);
  h_XX_YY_AccGain->Fill(35,34,61.4737);
  
  h_XX_YY_AccGain->Fill(36,20,49.2932);
  h_XX_YY_AccGain->Fill(36,21,45.2331);
  h_XX_YY_AccGain->Fill(36,22,44.9323);
  h_XX_YY_AccGain->Fill(36,23,46.5564);
  h_XX_YY_AccGain->Fill(36,24,47.2481);
  h_XX_YY_AccGain->Fill(36,25,58.1053);
  h_XX_YY_AccGain->Fill(36,26,81.3534);
  h_XX_YY_AccGain->Fill(36,27,83.9699);
  h_XX_YY_AccGain->Fill(36,28,87.188);
  h_XX_YY_AccGain->Fill(36,29,90.2256);
  h_XX_YY_AccGain->Fill(36,30,92.1504);
  h_XX_YY_AccGain->Fill(36,31,87.1579);
  h_XX_YY_AccGain->Fill(36,32,83.835);
  h_XX_YY_AccGain->Fill(36,33,81.0827);
  h_XX_YY_AccGain->Fill(36,34,61.4737);
  
  h_XX_YY_AccGain->Fill(37,20,45.8045);
  h_XX_YY_AccGain->Fill(37,21,44.0602);
  h_XX_YY_AccGain->Fill(37,22,43.7293);
  h_XX_YY_AccGain->Fill(37,23,43.3985);
  h_XX_YY_AccGain->Fill(37,24,46.9474);
  h_XX_YY_AccGain->Fill(37,25,57.9248);
  h_XX_YY_AccGain->Fill(37,26,84.0902);
  h_XX_YY_AccGain->Fill(37,27,87.3383);
  h_XX_YY_AccGain->Fill(37,28,85.7744);
  h_XX_YY_AccGain->Fill(37,29,94.3759);
  h_XX_YY_AccGain->Fill(37,30,91.6391);
  h_XX_YY_AccGain->Fill(37,31,93.7744);
  h_XX_YY_AccGain->Fill(37,32,85.835);
  h_XX_YY_AccGain->Fill(37,33,81.0827);
  h_XX_YY_AccGain->Fill(37,34,61.4737);
 
  h_XX_YY_AccGain->Fill(38,20,44.6917);
  h_XX_YY_AccGain->Fill(38,21,45.0226);
  h_XX_YY_AccGain->Fill(38,22,45.0827);
  h_XX_YY_AccGain->Fill(38,23,44.812);
  h_XX_YY_AccGain->Fill(38,24,48.5113);
  h_XX_YY_AccGain->Fill(38,25,61.8045);
  h_XX_YY_AccGain->Fill(38,26,87.609);
  h_XX_YY_AccGain->Fill(38,27,90.8872);
  h_XX_YY_AccGain->Fill(38,28,89.9248);
  h_XX_YY_AccGain->Fill(38,29,100.301);
  h_XX_YY_AccGain->Fill(38,30,97.8947);
  h_XX_YY_AccGain->Fill(38,31,93.594);
  h_XX_YY_AccGain->Fill(38,32,85.835);
  h_XX_YY_AccGain->Fill(38,33,81.0827);
  h_XX_YY_AccGain->Fill(38,34,61.4737);
   
  h_XX_YY_AccGain->Fill(39,20,46.9474);
  h_XX_YY_AccGain->Fill(39,21,47.6692);
  h_XX_YY_AccGain->Fill(39,22,45.1128);
  h_XX_YY_AccGain->Fill(39,23,44.9023);
  h_XX_YY_AccGain->Fill(39,24,46.1353);
  h_XX_YY_AccGain->Fill(39,25,63.2782);
  h_XX_YY_AccGain->Fill(39,26,86.1955);
  h_XX_YY_AccGain->Fill(39,27,95.7594);
  h_XX_YY_AccGain->Fill(39,28,94.9474);
  h_XX_YY_AccGain->Fill(39,29,99.6391);
  h_XX_YY_AccGain->Fill(39,30,97.5338);
  h_XX_YY_AccGain->Fill(39,31,93.3534);
  h_XX_YY_AccGain->Fill(39,32,85.835);
  h_XX_YY_AccGain->Fill(39,33,81.0827);
  h_XX_YY_AccGain->Fill(39,34,61.4737);

  h_XX_YY_AccGain->Fill(40,20,47.7594);
  h_XX_YY_AccGain->Fill(40,21,45.8647);
  h_XX_YY_AccGain->Fill(40,22,46.0451);
  h_XX_YY_AccGain->Fill(40,23,43.218);
  h_XX_YY_AccGain->Fill(40,24,47.2481);
  h_XX_YY_AccGain->Fill(40,25,69.1429);
  h_XX_YY_AccGain->Fill(40,26,90.3759);
  h_XX_YY_AccGain->Fill(40,27,95.0977);
  h_XX_YY_AccGain->Fill(40,28,100.932);
  h_XX_YY_AccGain->Fill(40,29,99.2481);
  h_XX_YY_AccGain->Fill(40,30,97.2331);
  h_XX_YY_AccGain->Fill(40,31,93.203);
  h_XX_YY_AccGain->Fill(40,32,85.835);
  h_XX_YY_AccGain->Fill(40,33,81.0827);
  h_XX_YY_AccGain->Fill(40,34,61.4737);


  h_XX_YY_AccGain->SetBit(TH1::kNoStats);

  TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
  tex_cms->AddText("CMS Internal");
  tex_cms->SetTextSize(0.035);
  tex_cms->SetFillStyle(0);
  tex_cms->SetBorderSize(0);

  TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
  tex_lumi->AddText("2018 Simulation (13 TeV)");
  tex_lumi->SetTextSize(0.035);
  tex_lumi->SetFillStyle(0);
  tex_lumi->SetBorderSize(0);

  TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
  tex_run->AddText("ggF H#rightarrow#tau#tau");
  tex_run->SetTextColor(0);
  tex_run->SetTextSize(0.04);
  tex_run->SetFillStyle(0);
  tex_run->SetBorderSize(0);

  TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
  tex_cat->AddText("2-jet");
  tex_cat->SetTextColor(0);
  tex_cat->SetTextSize(0.04);
  tex_cat->SetFillStyle(0);
  tex_cat->SetBorderSize(0);

  TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
  tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
  tex_cuts1->SetTextColor(0);
  tex_cuts1->SetTextSize(0.03);
  tex_cuts1->SetFillStyle(0);
  tex_cuts1->SetBorderSize(0);

  TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
  tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
  tex_cuts2->SetTextColor(0);
  tex_cuts2->SetTextSize(0.03);
  tex_cuts2->SetFillStyle(0);
  tex_cuts2->SetBorderSize(0);

  h_XX_YY_AccGain->SetTitle("");
  h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
  h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
  h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
  h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
  h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
  h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
  h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
  h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
  h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
  h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
  h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
  //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
  gPad->Update();
  //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
  //gPad->Update();

  //gStyle->SetPalette(kSandyTerrain);

  h_XX_YY_AccGain->Draw("colz");
  tex_cms->Draw("same");
  tex_lumi->Draw("same");
  tex_run->Draw("same"); tex_cat->Draw("same");
  tex_cuts1->Draw("same");
  tex_cuts2->Draw("same");

  c1->SaveAs("plots/acceptance_gain_2jet_ggF.pdf","pdf");
  cout<<h_XX_YY_AccGain->GetMaximum()<<endl;
}



void plot_acceptance_0jet_ttH(){

    TCanvas *c1 = new TCanvas("c1","c1",600,650);
    c1->SetRightMargin(0.16);

    TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

    h_XX_YY_AccGain->Fill(32,20,0);
    h_XX_YY_AccGain->Fill(32,21,0);
    h_XX_YY_AccGain->Fill(32,22,0);
    h_XX_YY_AccGain->Fill(32,23,0);
    h_XX_YY_AccGain->Fill(32,24,0);
    h_XX_YY_AccGain->Fill(32,25,0);
    h_XX_YY_AccGain->Fill(32,26,0);
    h_XX_YY_AccGain->Fill(32,27,0);
    h_XX_YY_AccGain->Fill(32,28,0);
    h_XX_YY_AccGain->Fill(32,29,0);
    h_XX_YY_AccGain->Fill(32,30,0);
    h_XX_YY_AccGain->Fill(32,31,0);
    h_XX_YY_AccGain->Fill(32,32,0);
    h_XX_YY_AccGain->Fill(32,33,0);
    h_XX_YY_AccGain->Fill(32,34,0);
     
    h_XX_YY_AccGain->Fill(33,20,-5.11379);
    h_XX_YY_AccGain->Fill(33,21,-5.11379);
    h_XX_YY_AccGain->Fill(33,22,-5.11379);
    h_XX_YY_AccGain->Fill(33,23,-5.11379);
    h_XX_YY_AccGain->Fill(33,24,-5.11379);
    h_XX_YY_AccGain->Fill(33,25,-5.11379);
    h_XX_YY_AccGain->Fill(33,26,-5.11379);
    h_XX_YY_AccGain->Fill(33,27,-5.11379);
    h_XX_YY_AccGain->Fill(33,28,-5.11379);
    h_XX_YY_AccGain->Fill(33,29,-5.11379);
    h_XX_YY_AccGain->Fill(33,30,-5.11379);
    h_XX_YY_AccGain->Fill(33,31,-5.11379);
    h_XX_YY_AccGain->Fill(33,32,-5.11379);
    h_XX_YY_AccGain->Fill(33,33,-5.11379);
    h_XX_YY_AccGain->Fill(33,34,-5.11379);
     
    h_XX_YY_AccGain->Fill(34,20,-10.3154);
    h_XX_YY_AccGain->Fill(34,21,-10.3154);
    h_XX_YY_AccGain->Fill(34,22,-10.3154);
    h_XX_YY_AccGain->Fill(34,23,-10.3154);
    h_XX_YY_AccGain->Fill(34,24,-10.3154);
    h_XX_YY_AccGain->Fill(34,25,-10.3154);
    h_XX_YY_AccGain->Fill(34,26,-10.3154);
    h_XX_YY_AccGain->Fill(34,27,-10.3154);
    h_XX_YY_AccGain->Fill(34,28,-10.3154);
    h_XX_YY_AccGain->Fill(34,29,-10.3154);
    h_XX_YY_AccGain->Fill(34,30,-10.3154);
    h_XX_YY_AccGain->Fill(34,31,-10.3154);
    h_XX_YY_AccGain->Fill(34,32,-10.3154);
    h_XX_YY_AccGain->Fill(34,33,-10.3154);
    h_XX_YY_AccGain->Fill(34,34,-10.3154);
     
    h_XX_YY_AccGain->Fill(35,20,-15.2711);
    h_XX_YY_AccGain->Fill(35,21,-15.2711);
    h_XX_YY_AccGain->Fill(35,22,-15.2711);
    h_XX_YY_AccGain->Fill(35,23,-15.2711);
    h_XX_YY_AccGain->Fill(35,24,-15.2711);
    h_XX_YY_AccGain->Fill(35,25,-15.2711);
    h_XX_YY_AccGain->Fill(35,26,-15.2711);
    h_XX_YY_AccGain->Fill(35,27,-15.2711);
    h_XX_YY_AccGain->Fill(35,28,-15.2711);
    h_XX_YY_AccGain->Fill(35,29,-15.2711);
    h_XX_YY_AccGain->Fill(35,30,-15.2711);
    h_XX_YY_AccGain->Fill(35,31,-15.2711);
    h_XX_YY_AccGain->Fill(35,32,-15.2711);
    h_XX_YY_AccGain->Fill(35,33,-15.2711);
    h_XX_YY_AccGain->Fill(35,34,-15.2711);
     
    h_XX_YY_AccGain->Fill(36,20,-19.6995);
    h_XX_YY_AccGain->Fill(36,21,-19.6995);
    h_XX_YY_AccGain->Fill(36,22,-19.6995);
    h_XX_YY_AccGain->Fill(36,23,-19.6995);
    h_XX_YY_AccGain->Fill(36,24,-19.6995);
    h_XX_YY_AccGain->Fill(36,25,-19.6995);
    h_XX_YY_AccGain->Fill(36,26,-19.6995);
    h_XX_YY_AccGain->Fill(36,27,-19.6995);
    h_XX_YY_AccGain->Fill(36,28,-19.6995);
    h_XX_YY_AccGain->Fill(36,29,-19.6995);
    h_XX_YY_AccGain->Fill(36,30,-19.6995);
    h_XX_YY_AccGain->Fill(36,31,-19.6995);
    h_XX_YY_AccGain->Fill(36,32,-19.6995);
    h_XX_YY_AccGain->Fill(36,33,-19.6995);
    h_XX_YY_AccGain->Fill(36,34,-19.6995);
 
    h_XX_YY_AccGain->Fill(37,20,-23.8819);
    h_XX_YY_AccGain->Fill(37,21,-23.8819);
    h_XX_YY_AccGain->Fill(37,22,-23.8819);
    h_XX_YY_AccGain->Fill(37,23,-23.8819);
    h_XX_YY_AccGain->Fill(37,24,-23.8819);
    h_XX_YY_AccGain->Fill(37,25,-23.8819);
    h_XX_YY_AccGain->Fill(37,26,-23.8819);
    h_XX_YY_AccGain->Fill(37,27,-23.8819);
    h_XX_YY_AccGain->Fill(37,28,-23.8819);
    h_XX_YY_AccGain->Fill(37,29,-23.8819);
    h_XX_YY_AccGain->Fill(37,30,-23.8819);
    h_XX_YY_AccGain->Fill(37,31,-23.8819);
    h_XX_YY_AccGain->Fill(37,32,-23.8819);
    h_XX_YY_AccGain->Fill(37,33,-23.8819);
    h_XX_YY_AccGain->Fill(37,34,-23.8819);
 
    h_XX_YY_AccGain->Fill(38,20,-28.2049);
    h_XX_YY_AccGain->Fill(38,21,-28.2049);
    h_XX_YY_AccGain->Fill(38,22,-28.2049);
    h_XX_YY_AccGain->Fill(38,23,-28.2049);
    h_XX_YY_AccGain->Fill(38,24,-28.2049);
    h_XX_YY_AccGain->Fill(38,25,-28.2049);
    h_XX_YY_AccGain->Fill(38,26,-28.2049);
    h_XX_YY_AccGain->Fill(38,27,-28.2049);
    h_XX_YY_AccGain->Fill(38,28,-28.2049);
    h_XX_YY_AccGain->Fill(38,29,-28.2049);
    h_XX_YY_AccGain->Fill(38,30,-28.2049);
    h_XX_YY_AccGain->Fill(38,31,-28.2049);
    h_XX_YY_AccGain->Fill(38,32,-28.2049);
    h_XX_YY_AccGain->Fill(38,33,-28.2049);
    h_XX_YY_AccGain->Fill(38,34,-28.2049);
 
    h_XX_YY_AccGain->Fill(39,20,-32.2819);
    h_XX_YY_AccGain->Fill(39,21,-32.2819);
    h_XX_YY_AccGain->Fill(39,22,-32.2819);
    h_XX_YY_AccGain->Fill(39,23,-32.2819);
    h_XX_YY_AccGain->Fill(39,24,-32.2819);
    h_XX_YY_AccGain->Fill(39,25,-32.2819);
    h_XX_YY_AccGain->Fill(39,26,-32.2819);
    h_XX_YY_AccGain->Fill(39,27,-32.2819);
    h_XX_YY_AccGain->Fill(39,28,-32.2819);
    h_XX_YY_AccGain->Fill(39,29,-32.2819);
    h_XX_YY_AccGain->Fill(39,30,-32.2819);
    h_XX_YY_AccGain->Fill(39,31,-32.2819);
    h_XX_YY_AccGain->Fill(39,32,-32.2819);
    h_XX_YY_AccGain->Fill(39,33,-32.2819);
    h_XX_YY_AccGain->Fill(39,34,-32.2819);
 
    h_XX_YY_AccGain->Fill(40,20,-35.489);
    h_XX_YY_AccGain->Fill(40,21,-35.489);
    h_XX_YY_AccGain->Fill(40,22,-35.489);
    h_XX_YY_AccGain->Fill(40,23,-35.489);
    h_XX_YY_AccGain->Fill(40,24,-35.489);
    h_XX_YY_AccGain->Fill(40,25,-35.489);
    h_XX_YY_AccGain->Fill(40,26,-35.489);
    h_XX_YY_AccGain->Fill(40,27,-35.489);
    h_XX_YY_AccGain->Fill(40,28,-35.489);
    h_XX_YY_AccGain->Fill(40,29,-35.489);
    h_XX_YY_AccGain->Fill(40,30,-35.489);
    h_XX_YY_AccGain->Fill(40,31,-35.489);
    h_XX_YY_AccGain->Fill(40,32,-35.489);
    h_XX_YY_AccGain->Fill(40,33,-35.489);
    h_XX_YY_AccGain->Fill(40,34,-35.489);

    h_XX_YY_AccGain->SetBit(TH1::kNoStats);

    TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
    tex_cms->AddText("CMS Internal");
    tex_cms->SetTextSize(0.035);
    tex_cms->SetFillStyle(0);
    tex_cms->SetBorderSize(0);

    TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
    tex_lumi->AddText("2018 Simulation (13 TeV)");
    tex_lumi->SetTextSize(0.035);
    tex_lumi->SetFillStyle(0);
    tex_lumi->SetBorderSize(0);

    TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
    tex_run->AddText("ttH H#rightarrow#tau#tau");
    tex_run->SetTextColor(0);
    tex_run->SetTextSize(0.04);
    tex_run->SetFillStyle(0);
    tex_run->SetBorderSize(0);

    TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
    tex_cat->AddText("0-jet");
    tex_cat->SetTextColor(0);
    tex_cat->SetTextSize(0.04);
    tex_cat->SetFillStyle(0);
    tex_cat->SetBorderSize(0);

    TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
    tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
    tex_cuts1->SetTextColor(0);
    tex_cuts1->SetTextSize(0.03);
    tex_cuts1->SetFillStyle(0);
    tex_cuts1->SetBorderSize(0);

    TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
    tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
    tex_cuts2->SetTextColor(0);
    tex_cuts2->SetTextSize(0.03);
    tex_cuts2->SetFillStyle(0);
    tex_cuts2->SetBorderSize(0);

    h_XX_YY_AccGain->SetTitle("");
    h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
    h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
    h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
    h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
    h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
    h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
    h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
    h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
    h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
    //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
    gPad->Update();
    //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    //gPad->Update();

    //gStyle->SetPalette(kSandyTerrain);

    h_XX_YY_AccGain->Draw("colz");
    tex_cms->Draw("same");
    tex_lumi->Draw("same");
    tex_run->Draw("same"); tex_cat->Draw("same");
    tex_cuts1->Draw("same");
    tex_cuts2->Draw("same");

    c1->SaveAs("plots/acceptance_gain_0jet_ttH.pdf","pdf");
    cout<<h_XX_YY_AccGain->GetMaximum()<<endl;
}


void plot_acceptance_1jet_ttH(){

    TCanvas *c1 = new TCanvas("c1","c1",600,650);
    c1->SetRightMargin(0.16);

    TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

    h_XX_YY_AccGain->Fill(32,20,25.9513);
    h_XX_YY_AccGain->Fill(32,21,23.4203);
    h_XX_YY_AccGain->Fill(32,22,20.9597);
    h_XX_YY_AccGain->Fill(32,23,22.2252);
    h_XX_YY_AccGain->Fill(32,24,24.3167);
    h_XX_YY_AccGain->Fill(32,25,22.9282);
    h_XX_YY_AccGain->Fill(32,26,21.0036);
    h_XX_YY_AccGain->Fill(32,27,17.0138);
    h_XX_YY_AccGain->Fill(32,28,13.4019);
    h_XX_YY_AccGain->Fill(32,29,12.7428);
    h_XX_YY_AccGain->Fill(32,30,8.49811);
    h_XX_YY_AccGain->Fill(32,31,5.79137);
    h_XX_YY_AccGain->Fill(32,32,0);
    h_XX_YY_AccGain->Fill(32,33,0);
    h_XX_YY_AccGain->Fill(32,34,0);
 
    h_XX_YY_AccGain->Fill(33,20,43.3342);
    h_XX_YY_AccGain->Fill(33,21,38.5711);
    h_XX_YY_AccGain->Fill(33,22,36.207);
    h_XX_YY_AccGain->Fill(33,23,32.6566);
    h_XX_YY_AccGain->Fill(33,24,34.8625);
    h_XX_YY_AccGain->Fill(33,25,32.9203);
    h_XX_YY_AccGain->Fill(33,26,34.7219);
    h_XX_YY_AccGain->Fill(33,27,28.9744);
    h_XX_YY_AccGain->Fill(33,28,24.6858);
    h_XX_YY_AccGain->Fill(33,29,19.2372);
    h_XX_YY_AccGain->Fill(33,30,12.3561);
    h_XX_YY_AccGain->Fill(33,31,5.95834);
    h_XX_YY_AccGain->Fill(33,32,0);
    h_XX_YY_AccGain->Fill(33,33,-5.11468);
    h_XX_YY_AccGain->Fill(33,34,-5.11468);
 
    h_XX_YY_AccGain->Fill(34,20,44.8458);
    h_XX_YY_AccGain->Fill(34,21,42.6663);
    h_XX_YY_AccGain->Fill(34,22,38.905);
    h_XX_YY_AccGain->Fill(34,23,36.0313);
    h_XX_YY_AccGain->Fill(34,24,37.7538);
    h_XX_YY_AccGain->Fill(34,25,36.4355);
    h_XX_YY_AccGain->Fill(34,26,38.0526);
    h_XX_YY_AccGain->Fill(34,27,31.6636);
    h_XX_YY_AccGain->Fill(34,28,25.5471);
    h_XX_YY_AccGain->Fill(34,29,19.4481);
    h_XX_YY_AccGain->Fill(34,30,12.4);
    h_XX_YY_AccGain->Fill(34,31,5.97592);
    h_XX_YY_AccGain->Fill(34,32,0);
    h_XX_YY_AccGain->Fill(34,33,-5.11468);
    h_XX_YY_AccGain->Fill(34,34,-10.3173);
 
    h_XX_YY_AccGain->Fill(35,20,49.3189);
    h_XX_YY_AccGain->Fill(35,21,45.1621);
    h_XX_YY_AccGain->Fill(35,22,42.5696);
    h_XX_YY_AccGain->Fill(35,23,39.7135);
    h_XX_YY_AccGain->Fill(35,24,39.9156);
    h_XX_YY_AccGain->Fill(35,25,40.8296);
    h_XX_YY_AccGain->Fill(35,26,39.5377);
    h_XX_YY_AccGain->Fill(35,27,32.9554);
    h_XX_YY_AccGain->Fill(35,28,26.1007);
    h_XX_YY_AccGain->Fill(35,29,19.703);
    h_XX_YY_AccGain->Fill(35,30,12.4967);
    h_XX_YY_AccGain->Fill(35,31,5.98471);
    h_XX_YY_AccGain->Fill(35,32,0);
    h_XX_YY_AccGain->Fill(35,33,-5.11468);
    h_XX_YY_AccGain->Fill(35,34,-10.3173);
 
    h_XX_YY_AccGain->Fill(36,20,51.182);
    h_XX_YY_AccGain->Fill(36,21,45.0918);
    h_XX_YY_AccGain->Fill(36,22,42.8421);
    h_XX_YY_AccGain->Fill(36,23,41.3042);
    h_XX_YY_AccGain->Fill(36,24,38.7908);
    h_XX_YY_AccGain->Fill(36,25,40.1793);
    h_XX_YY_AccGain->Fill(36,26,39.9596);
    h_XX_YY_AccGain->Fill(36,27,33.1576);
    h_XX_YY_AccGain->Fill(36,28,26.2062);
    h_XX_YY_AccGain->Fill(36,29,19.6766);
    h_XX_YY_AccGain->Fill(36,30,12.4791);
    h_XX_YY_AccGain->Fill(36,31,5.98471);
    h_XX_YY_AccGain->Fill(36,32,0);
    h_XX_YY_AccGain->Fill(36,33,-5.11468);
    h_XX_YY_AccGain->Fill(36,34,-10.3173);
 
    h_XX_YY_AccGain->Fill(37,20,49.5914);
    h_XX_YY_AccGain->Fill(37,21,45.3643);
    h_XX_YY_AccGain->Fill(37,22,43.0354);
    h_XX_YY_AccGain->Fill(37,23,40.0387);
    h_XX_YY_AccGain->Fill(37,24,39.0983);
    h_XX_YY_AccGain->Fill(37,25,40.6978);
    h_XX_YY_AccGain->Fill(37,26,40.2496);
    h_XX_YY_AccGain->Fill(37,27,33.4476);
    h_XX_YY_AccGain->Fill(37,28,26.1622);
    h_XX_YY_AccGain->Fill(37,29,19.7381);
    h_XX_YY_AccGain->Fill(37,30,12.4703);
    h_XX_YY_AccGain->Fill(37,31,5.97592);
    h_XX_YY_AccGain->Fill(37,32,0);
    h_XX_YY_AccGain->Fill(37,33,-5.11468);
    h_XX_YY_AccGain->Fill(37,34,-10.3173);
 
    h_XX_YY_AccGain->Fill(38,20,50.1714);
    h_XX_YY_AccGain->Fill(38,21,47.948);
    h_XX_YY_AccGain->Fill(38,22,45.3643);
    h_XX_YY_AccGain->Fill(38,23,42.1742);
    h_XX_YY_AccGain->Fill(38,24,41.2426);
    h_XX_YY_AccGain->Fill(38,25,42.2796);
    h_XX_YY_AccGain->Fill(38,26,40.5835);
    h_XX_YY_AccGain->Fill(38,27,33.6497);
    h_XX_YY_AccGain->Fill(38,28,26.2853);
    h_XX_YY_AccGain->Fill(38,29,19.8524);
    h_XX_YY_AccGain->Fill(38,30,12.4967);
    h_XX_YY_AccGain->Fill(38,31,5.97592);
    h_XX_YY_AccGain->Fill(38,32,0);
    h_XX_YY_AccGain->Fill(38,33,-5.11468);
    h_XX_YY_AccGain->Fill(38,34,-10.3173);
 
    h_XX_YY_AccGain->Fill(39,20,53.1857);
    h_XX_YY_AccGain->Fill(39,21,50.6723);
    h_XX_YY_AccGain->Fill(39,22,46.1025);
    h_XX_YY_AccGain->Fill(39,23,42.7278);
    h_XX_YY_AccGain->Fill(39,24,40.3814);
    h_XX_YY_AccGain->Fill(39,25,42.8509);
    h_XX_YY_AccGain->Fill(39,26,40.4166);
    h_XX_YY_AccGain->Fill(39,27,33.7991);
    h_XX_YY_AccGain->Fill(39,28,26.3819);
    h_XX_YY_AccGain->Fill(39,29,19.8436);
    h_XX_YY_AccGain->Fill(39,30,12.4879);
    h_XX_YY_AccGain->Fill(39,31,5.97592);
    h_XX_YY_AccGain->Fill(39,32,0);
    h_XX_YY_AccGain->Fill(39,33,-5.11468);
    h_XX_YY_AccGain->Fill(39,34,-10.3173);

    h_XX_YY_AccGain->Fill(40,20,54.3721);
    h_XX_YY_AccGain->Fill(40,21,49.7232);
    h_XX_YY_AccGain->Fill(40,22,47.0164);
    h_XX_YY_AccGain->Fill(40,23,41.9193);
    h_XX_YY_AccGain->Fill(40,24,41.1635);
    h_XX_YY_AccGain->Fill(40,25,44.5294);
    h_XX_YY_AccGain->Fill(40,26,40.7944);
    h_XX_YY_AccGain->Fill(40,27,33.7376);
    h_XX_YY_AccGain->Fill(40,28,26.5138);
    h_XX_YY_AccGain->Fill(40,29,19.8436);
    h_XX_YY_AccGain->Fill(40,30,12.4879);
    h_XX_YY_AccGain->Fill(40,31,5.97592);
    h_XX_YY_AccGain->Fill(40,32,0);
    h_XX_YY_AccGain->Fill(40,33,-5.11468);
    h_XX_YY_AccGain->Fill(40,34,-10.3173);

    h_XX_YY_AccGain->SetBit(TH1::kNoStats);

    TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
    tex_cms->AddText("CMS Internal");
    tex_cms->SetTextSize(0.035);
    tex_cms->SetFillStyle(0);
    tex_cms->SetBorderSize(0);

    TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
    tex_lumi->AddText("2018 Simulation (13 TeV)");
    tex_lumi->SetTextSize(0.035);
    tex_lumi->SetFillStyle(0);
    tex_lumi->SetBorderSize(0);

    TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
    tex_run->AddText("ttH H#rightarrow#tau#tau");
    tex_run->SetTextColor(0);
    tex_run->SetTextSize(0.04);
    tex_run->SetFillStyle(0);
    tex_run->SetBorderSize(0);

    TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
    tex_cat->AddText("1-jet");
    tex_cat->SetTextColor(0);
    tex_cat->SetTextSize(0.04);
    tex_cat->SetFillStyle(0);
    tex_cat->SetBorderSize(0);

    TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
    tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
    tex_cuts1->SetTextColor(0);
    tex_cuts1->SetTextSize(0.03);
    tex_cuts1->SetFillStyle(0);
    tex_cuts1->SetBorderSize(0);

    TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
    tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
    tex_cuts2->SetTextColor(0);
    tex_cuts2->SetTextSize(0.03);
    tex_cuts2->SetFillStyle(0);
    tex_cuts2->SetBorderSize(0);

    h_XX_YY_AccGain->SetTitle("");
    h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
    h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
    h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
    h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
    h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
    h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
    h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
    h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
    h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
    //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
    gPad->Update();
    //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    //gPad->Update();

    //gStyle->SetPalette(kSandyTerrain);

    h_XX_YY_AccGain->Draw("colz");
    tex_cms->Draw("same");
    tex_lumi->Draw("same");
    tex_run->Draw("same"); tex_cat->Draw("same");
    tex_cuts1->Draw("same");
    tex_cuts2->Draw("same");

    c1->SaveAs("plots/acceptance_gain_1jet_ttH.pdf","pdf");
    cout<<h_XX_YY_AccGain->GetMaximum()<<endl;
}


void plot_acceptance_2jet_ttH(){

    TCanvas *c1 = new TCanvas("c1","c1",600,650);
    c1->SetRightMargin(0.16);

    TH2F* h_XX_YY_AccGain = new TH2F("h_XX_YY_AccGain","h_XX_YY_AccGain",10,30,40,32,18,50);

    h_XX_YY_AccGain->Fill(32,20,26.1823);
    h_XX_YY_AccGain->Fill(32,21,23.6365);
    h_XX_YY_AccGain->Fill(32,22,21.1615);
    h_XX_YY_AccGain->Fill(32,23,22.4432);
    h_XX_YY_AccGain->Fill(32,24,24.5912);
    h_XX_YY_AccGain->Fill(32,25,23.2034);
    h_XX_YY_AccGain->Fill(32,26,21.2852);
    h_XX_YY_AccGain->Fill(32,27,17.2722);
    h_XX_YY_AccGain->Fill(32,28,13.6392);
    h_XX_YY_AccGain->Fill(32,29,13.0293);
    h_XX_YY_AccGain->Fill(32,30,8.76867);
    h_XX_YY_AccGain->Fill(32,31,6.20525);
    h_XX_YY_AccGain->Fill(32,32,0.5834);
    h_XX_YY_AccGain->Fill(32,33,0.556881);
    h_XX_YY_AccGain->Fill(32,34,0.530363);
 
    h_XX_YY_AccGain->Fill(33,20,43.7638);
    h_XX_YY_AccGain->Fill(33,21,38.9729);
    h_XX_YY_AccGain->Fill(33,22,36.6039);
    h_XX_YY_AccGain->Fill(33,23,33.0328);
    h_XX_YY_AccGain->Fill(33,24,35.2957);
    h_XX_YY_AccGain->Fill(33,25,33.351);
    h_XX_YY_AccGain->Fill(33,26,35.225);
    h_XX_YY_AccGain->Fill(33,27,29.4705);
    h_XX_YY_AccGain->Fill(33,28,25.1746);
    h_XX_YY_AccGain->Fill(33,29,19.7649);
    h_XX_YY_AccGain->Fill(33,30,12.932);
    h_XX_YY_AccGain->Fill(33,31,6.51463);
    h_XX_YY_AccGain->Fill(33,32,0.5834);
    h_XX_YY_AccGain->Fill(33,33,-4.56112);
    h_XX_YY_AccGain->Fill(33,34,-4.58764);
 
    h_XX_YY_AccGain->Fill(34,20,45.3107);
    h_XX_YY_AccGain->Fill(34,21,43.1362);
    h_XX_YY_AccGain->Fill(34,22,39.3618);
    h_XX_YY_AccGain->Fill(34,23,36.489);
    h_XX_YY_AccGain->Fill(34,24,38.2304);
    h_XX_YY_AccGain->Fill(34,25,36.931);
    h_XX_YY_AccGain->Fill(34,26,38.6193);
    h_XX_YY_AccGain->Fill(34,27,32.1931);
    h_XX_YY_AccGain->Fill(34,28,26.085);
    h_XX_YY_AccGain->Fill(34,29,20.0477);
    h_XX_YY_AccGain->Fill(34,30,12.9939);
    h_XX_YY_AccGain->Fill(34,31,6.54115);
    h_XX_YY_AccGain->Fill(34,32,0.5834);
    h_XX_YY_AccGain->Fill(34,33,-4.56112);
    h_XX_YY_AccGain->Fill(34,34,-9.79404);
 
    h_XX_YY_AccGain->Fill(35,20,49.863);
    h_XX_YY_AccGain->Fill(35,21,45.6908);
    h_XX_YY_AccGain->Fill(35,22,43.0832);
    h_XX_YY_AccGain->Fill(35,23,40.2192);
    h_XX_YY_AccGain->Fill(35,24,40.449);
    h_XX_YY_AccGain->Fill(35,25,41.386);
    h_XX_YY_AccGain->Fill(35,26,40.1397);
    h_XX_YY_AccGain->Fill(35,27,33.5455);
    h_XX_YY_AccGain->Fill(35,28,26.7215);
    h_XX_YY_AccGain->Fill(35,29,20.3218);
    h_XX_YY_AccGain->Fill(35,30,13.1);
    h_XX_YY_AccGain->Fill(35,31,6.54999);
    h_XX_YY_AccGain->Fill(35,32,0.5834);
    h_XX_YY_AccGain->Fill(35,33,-4.56112);
    h_XX_YY_AccGain->Fill(35,34,-9.79404);
 
    h_XX_YY_AccGain->Fill(36,20,51.7635);
    h_XX_YY_AccGain->Fill(36,21,45.6378);
    h_XX_YY_AccGain->Fill(36,22,43.3749);
    h_XX_YY_AccGain->Fill(36,23,41.8368);
    h_XX_YY_AccGain->Fill(36,24,39.3353);
    h_XX_YY_AccGain->Fill(36,25,40.7496);
    h_XX_YY_AccGain->Fill(36,26,40.5816);
    h_XX_YY_AccGain->Fill(36,27,33.7753);
    h_XX_YY_AccGain->Fill(36,28,26.8452);
    h_XX_YY_AccGain->Fill(36,29,20.2952);
    h_XX_YY_AccGain->Fill(36,30,13.0823);
    h_XX_YY_AccGain->Fill(36,31,6.54999);
    h_XX_YY_AccGain->Fill(36,32,0.5834);
    h_XX_YY_AccGain->Fill(36,33,-4.56112);
    h_XX_YY_AccGain->Fill(36,34,-9.79404);
 
    h_XX_YY_AccGain->Fill(37,20,50.1812);
    h_XX_YY_AccGain->Fill(37,21,45.9295);
    h_XX_YY_AccGain->Fill(37,22,43.5959);
    h_XX_YY_AccGain->Fill(37,23,40.5816);
    h_XX_YY_AccGain->Fill(37,24,39.6623);
    h_XX_YY_AccGain->Fill(37,25,41.2888);
    h_XX_YY_AccGain->Fill(37,26,40.891);
    h_XX_YY_AccGain->Fill(37,27,34.0935);
    h_XX_YY_AccGain->Fill(37,28,26.8099);
    h_XX_YY_AccGain->Fill(37,29,20.3836);
    h_XX_YY_AccGain->Fill(37,30,13.0823);
    h_XX_YY_AccGain->Fill(37,31,6.55883);
    h_XX_YY_AccGain->Fill(37,32,0.5834);
    h_XX_YY_AccGain->Fill(37,33,-4.56112);
    h_XX_YY_AccGain->Fill(37,34,-9.79404);
 
    h_XX_YY_AccGain->Fill(38,20,50.7646);
    h_XX_YY_AccGain->Fill(38,21,48.5371);
    h_XX_YY_AccGain->Fill(38,22,45.9383);
    h_XX_YY_AccGain->Fill(38,23,42.7384);
    h_XX_YY_AccGain->Fill(38,24,41.828);
    h_XX_YY_AccGain->Fill(38,25,42.9152);
    h_XX_YY_AccGain->Fill(38,26,41.2357);
    h_XX_YY_AccGain->Fill(38,27,34.3233);
    h_XX_YY_AccGain->Fill(38,28,26.9336);
    h_XX_YY_AccGain->Fill(38,29,20.4985);
    h_XX_YY_AccGain->Fill(38,30,13.1088);
    h_XX_YY_AccGain->Fill(38,31,6.55883);
    h_XX_YY_AccGain->Fill(38,32,0.5834);
    h_XX_YY_AccGain->Fill(38,33,-4.56112);
    h_XX_YY_AccGain->Fill(38,34,-9.79404);
 
    h_XX_YY_AccGain->Fill(39,20,53.8142);
    h_XX_YY_AccGain->Fill(39,21,51.2861);
    h_XX_YY_AccGain->Fill(39,22,46.6896);
    h_XX_YY_AccGain->Fill(39,23,43.3218);
    h_XX_YY_AccGain->Fill(39,24,40.9706);
    h_XX_YY_AccGain->Fill(39,25,43.4986);
    h_XX_YY_AccGain->Fill(39,26,41.0678);
    h_XX_YY_AccGain->Fill(39,27,34.4913);
    h_XX_YY_AccGain->Fill(39,28,27.0485);
    h_XX_YY_AccGain->Fill(39,29,20.4897);
    h_XX_YY_AccGain->Fill(39,30,13.1);
    h_XX_YY_AccGain->Fill(39,31,6.55883);
    h_XX_YY_AccGain->Fill(39,32,0.5834);
    h_XX_YY_AccGain->Fill(39,33,-4.56112);
    h_XX_YY_AccGain->Fill(39,34,-9.79404);
 
    h_XX_YY_AccGain->Fill(40,20,55.0164);
    h_XX_YY_AccGain->Fill(40,21,50.3403);
    h_XX_YY_AccGain->Fill(40,22,47.6266);
    h_XX_YY_AccGain->Fill(40,23,42.5175);
    h_XX_YY_AccGain->Fill(40,24,41.7661);
    h_XX_YY_AccGain->Fill(40,25,45.187);
    h_XX_YY_AccGain->Fill(40,26,41.4656);
    h_XX_YY_AccGain->Fill(40,27,34.4294);
    h_XX_YY_AccGain->Fill(40,28,27.1811);
    h_XX_YY_AccGain->Fill(40,29,20.4897);
    h_XX_YY_AccGain->Fill(40,30,13.1);
    h_XX_YY_AccGain->Fill(40,31,6.55883);
    h_XX_YY_AccGain->Fill(40,32,0.5834);
    h_XX_YY_AccGain->Fill(40,33,-4.56112);
    h_XX_YY_AccGain->Fill(40,34,-9.79404);

    h_XX_YY_AccGain->SetBit(TH1::kNoStats);

    TPaveText* tex_cms = new TPaveText(0.12,0.92,0.30,0.93,"NDC");
    tex_cms->AddText("CMS Internal");
    tex_cms->SetTextSize(0.035);
    tex_cms->SetFillStyle(0);
    tex_cms->SetBorderSize(0);

    TPaveText* tex_lumi = new TPaveText(0.57,0.91,0.71,0.93,"NDC");
    tex_lumi->AddText("2018 Simulation (13 TeV)");
    tex_lumi->SetTextSize(0.035);
    tex_lumi->SetFillStyle(0);
    tex_lumi->SetBorderSize(0);

    TPaveText* tex_run = new TPaveText(0.68,0.85,0.7,0.86,"NDC");
    tex_run->AddText("ttH H#rightarrow#tau#tau");
    tex_run->SetTextColor(0);
    tex_run->SetTextSize(0.04);
    tex_run->SetFillStyle(0);
    tex_run->SetBorderSize(0);

    TPaveText* tex_cat = new TPaveText(0.68,0.8,0.7,0.81,"NDC");
    tex_cat->AddText("2-jet");
    tex_cat->SetTextColor(0);
    tex_cat->SetTextSize(0.04);
    tex_cat->SetFillStyle(0);
    tex_cat->SetBorderSize(0);

    TPaveText* tex_cuts1 = new TPaveText(0.55,0.74,0.57,0.75,"NDC");
    tex_cuts1->AddText("DoubleIsoTauXXer2p1 OR");
    tex_cuts1->SetTextColor(0);
    tex_cuts1->SetTextSize(0.03);
    tex_cuts1->SetFillStyle(0);
    tex_cuts1->SetBorderSize(0);

    TPaveText* tex_cuts2 = new TPaveText(0.55,0.71,0.57,0.72,"NDC");
    tex_cuts2->AddText("DoubleIsoTauYYer2p1JetZZdR0p5");
    tex_cuts2->SetTextColor(0);
    tex_cuts2->SetTextSize(0.03);
    tex_cuts2->SetFillStyle(0);
    tex_cuts2->SetBorderSize(0);

    h_XX_YY_AccGain->SetTitle("");
    h_XX_YY_AccGain->GetXaxis()->SetTitleOffset(1.1);
    h_XX_YY_AccGain->GetZaxis()->SetTitleOffset(1.4);
    h_XX_YY_AccGain->GetXaxis()->SetTitle("XX [GeV]");
    h_XX_YY_AccGain->GetYaxis()->SetTitle("YY [GeV]");
    h_XX_YY_AccGain->GetZaxis()->SetTitle("Acceptance gain wrt DoubleIsoTau32er2p1 [%]");
    h_XX_YY_AccGain->GetXaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    h_XX_YY_AccGain->GetYaxis()->SetNdivisions(16);
    h_XX_YY_AccGain->GetXaxis()->SetNdivisions(9);
    h_XX_YY_AccGain->GetXaxis()->SetRangeUser(32.,41.);
    h_XX_YY_AccGain->GetYaxis()->SetRangeUser(20.,35.);
    //h_XX_YY_AccGain->GetZaxis()->SetRangeUser(19.,141.);
    gPad->Update();
    //h_XX_YY_AccGain->GetYaxis()->CenterLabels(true);
    //gPad->Update();

    //gStyle->SetPalette(kSandyTerrain);

    h_XX_YY_AccGain->Draw("colz");
    tex_cms->Draw("same");
    tex_lumi->Draw("same");
    tex_run->Draw("same"); tex_cat->Draw("same");
    tex_cuts1->Draw("same");
    tex_cuts2->Draw("same");

    c1->SaveAs("plots/acceptance_gain_2jet_ttH.pdf","pdf");
    cout<<h_XX_YY_AccGain->GetMaximum()<<endl;
}

