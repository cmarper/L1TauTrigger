{

    const Int_t nbins = 11;
    float pT_edges[nbins+1] = { 20, 25, 30, 35, 40, 45, 50, 60, 80, 120, 180, 255};	
 
	float tau_barrel_mean[11] = { 1.154, 1.083, 1.039, 1.011, 0.993, 0.978, 0.962, 0.946, 0.942, 1.002, 1.049};
	float tau_barrel_res[11] = { 22.9, 23.3, 22.7, 22.2, 21.1, 20.1, 18.7, 16.8, 15.3, 22.5, 17.2};

	float tau_endcap_mean[11] = { 1.136, 1.062, 1.027, 1.004, 0.994, 0.988, 0.981, 0.975, 0.970, 0.993, 1.018};
	float tau_endcap_res[11] = { 23.4, 23.4, 23.1, 22.0, 20.0, 19.4, 17.1, 14.9, 12.8, 17.2, 15.5};

	float jet_barrel_mean[11] = { 1.155, 1.202, 1.207, 1.201, 1.194, 1.185, 1.172, 1.143, 1.112, 1.109, 1.139};
	float jet_barrel_res[11] = { 31.2, 27.8, 26.4, 25.4, 24.1, 22.7, 21.0, 18.8, 17.2, 16.4, 16.8};

	float jet_endcap_mean[11] = { 1.115, 1.252, 1.331, 1.351, 1.347, 1.329, 1.300, 1.251, 1.183, 1.120, 1.081};
	float jet_endcap_res[11] = { 34.7, 30.6, 26.7, 23.6, 21.4, 20.0, 18.7, 16.9, 14.9, 13.2, 13.3};


    TH1F *h_tau_barrel_mean = new TH1F("h_tau_barrel_mean","h_tau_barrel_mean",nbins,pT_edges);
    for (int i=0; i<12; i++){ 
    	h_tau_barrel_mean->AddBinContent(i+1,tau_barrel_mean[i]);
    	h_tau_barrel_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_tau_endcap_mean = new TH1F("h_tau_endcap_mean","h_tau_endcap_mean",nbins,pT_edges);
    for (int i=0; i<12; i++){ 
    	h_tau_endcap_mean->AddBinContent(i+1,tau_endcap_mean[i]);
    	h_tau_endcap_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_tau_barrel_res = new TH1F("h_tau_barrel_res","h_tau_barrel_res",nbins,pT_edges);
    for (int i=0; i<12; i++){ 
    	h_tau_barrel_res->AddBinContent(i+1,tau_barrel_res[i]);
    	h_tau_barrel_res->SetBinError(i+1,0.000001);
    }

    TH1F *h_tau_endcap_res = new TH1F("h_tau_endcap_res","h_tau_endcap_res",nbins,pT_edges);
    for (int i=0; i<12; i++){ 
    	h_tau_endcap_res->AddBinContent(i+1,tau_endcap_res[i]);
    	h_tau_endcap_res->SetBinError(i+1,0.000001);
    }

        TH1F *h_jet_barrel_mean = new TH1F("h_jet_barrel_mean","h_jet_barrel_mean",nbins,pT_edges);
    for (int i=0; i<12; i++){ 
    	h_jet_barrel_mean->AddBinContent(i+1,jet_barrel_mean[i]);
    	h_jet_barrel_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_endcap_mean = new TH1F("h_jet_endcap_mean","h_jet_endcap_mean",nbins,pT_edges);
    for (int i=0; i<12; i++){ 
    	h_jet_endcap_mean->AddBinContent(i+1,jet_endcap_mean[i]);
    	h_jet_endcap_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_barrel_res = new TH1F("h_jet_barrel_res","h_jet_barrel_res",nbins,pT_edges);
    for (int i=0; i<12; i++){ 
    	h_jet_barrel_res->AddBinContent(i+1,jet_barrel_res[i]);
    	h_jet_barrel_res->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_endcap_res = new TH1F("h_jet_endcap_res","h_jet_endcap_res",nbins,pT_edges);
    for (int i=0; i<12; i++){ 
    	h_jet_endcap_res->AddBinContent(i+1,jet_endcap_res[i]);
    	h_jet_endcap_res->SetBinError(i+1,0.000001);
    }

    TPaveText* texl = new TPaveText(0.25,0.86,0.93,0.98, "NDC");
    texl->AddText("CMS Internal, #sqrt{s}=13 TeV, 2018 MC VBF H #rightarrow #tau#tau");
    texl->SetTextSize(0.03);
    texl->SetFillStyle(0);
    texl->SetBorderSize(0);
    

    TCanvas *c1 = new TCanvas("c1","c1",800,900);
    gStyle->SetOptStat(0);
	c1->cd();
	c1->SetGrid();

	h_jet_endcap_mean->SetLineColor(kRed);
	h_jet_endcap_mean->SetMarkerStyle(20);
	h_jet_endcap_mean->SetMarkerSize(1.5);
	h_jet_endcap_mean->SetMarkerColor(kRed);
    h_jet_endcap_mean->SetLineWidth(2);
    h_jet_endcap_mean->SetMaximum(1.45);
	h_jet_endcap_mean->SetMinimum(0.8);
	h_jet_endcap_mean->GetXaxis()->SetTitle("p_{T}^{offline} [GeV]");
	h_jet_endcap_mean->GetYaxis()->SetTitle("< E_{T}^{L1}/p_{T}^{offline} >");
	h_jet_endcap_mean->SetTitle(" ");
    h_jet_endcap_mean->Draw("E");

    h_jet_barrel_mean->SetLineColor(kRed);
    h_jet_barrel_mean->SetMarkerStyle(24);
    h_jet_barrel_mean->SetMarkerSize(1.5);
    h_jet_barrel_mean->SetMarkerColor(kRed);
    h_jet_barrel_mean->SetLineWidth(2);
    h_jet_barrel_mean->Draw("E same");

	h_tau_barrel_mean->SetLineColor(kBlue);
	h_tau_barrel_mean->SetMarkerStyle(24);
	h_tau_barrel_mean->SetMarkerSize(1.5);
	h_tau_barrel_mean->SetMarkerColor(kBlue);
	h_tau_barrel_mean->SetLineWidth(2);
    h_tau_barrel_mean->Draw("E same");

    h_tau_endcap_mean->SetLineColor(kBlue);
    h_tau_endcap_mean->SetMarkerStyle(20);
    h_tau_endcap_mean->SetMarkerSize(1.5);
    h_tau_endcap_mean->SetMarkerColor(kBlue);
    h_tau_endcap_mean->SetLineWidth(2);
    h_tau_endcap_mean->Draw("E same");

    auto legend1 = new TLegend(0.5,0.75,0.9,0.85);
    legend1->SetBorderSize(0);
    legend1->SetNColumns(2);

    legend1->AddEntry(h_jet_barrel_mean,"Jets Barrel","apl");
    legend1->AddEntry(h_tau_barrel_mean,"Taus Barrel","apl");
    legend1->AddEntry(h_jet_endcap_mean,"Jets Endcap","apl");
    legend1->AddEntry(h_tau_endcap_mean,"Taus Endcap","apl");
    legend1->Draw();
    texl->Draw("same");

    c1->Print("mean_L1jetstaus.pdf", "pdf");
	c1->Print("mean_L1jetstaus.png", "png");
    
    TCanvas *c2 = new TCanvas("c2","c2",800,900);
    gStyle->SetOptStat(0);
    c2->cd();
    c2->SetGrid();

    h_jet_endcap_res->SetLineColor(kRed);
    h_jet_endcap_res->SetMarkerStyle(20);
    h_jet_endcap_res->SetMarkerSize(1.5);
    h_jet_endcap_res->SetMarkerColor(kRed);
    h_jet_endcap_res->SetLineWidth(2);
    h_jet_endcap_res->SetMaximum(37);
    h_jet_endcap_res->SetMinimum(10);
    h_jet_endcap_res->GetXaxis()->SetTitle("p_{T}^{offline} [GeV]");
    h_jet_endcap_res->GetYaxis()->SetTitle("RMS / <E_{T}^{L1}/p_{T}^{offline}> [%]");
    h_jet_endcap_res->SetTitle(" ");
    h_jet_endcap_res->Draw("E");

    h_jet_barrel_res->SetLineColor(kRed);
    h_jet_barrel_res->SetMarkerStyle(4);
    h_jet_barrel_res->SetMarkerSize(1.5);
    h_jet_barrel_res->SetMarkerColor(kRed);
    h_jet_barrel_res->SetLineWidth(2);
    h_jet_barrel_res->Draw("E same");

    h_tau_barrel_res->SetLineColor(kBlue);
    h_tau_barrel_res->SetMarkerStyle(4);
    h_tau_barrel_res->SetMarkerSize(1.5);
    h_tau_barrel_res->SetMarkerColor(kBlue);
    h_tau_barrel_res->SetLineWidth(2);
    h_tau_barrel_res->Draw("E same");

    h_tau_endcap_res->SetLineColor(kBlue);
    h_tau_endcap_res->SetMarkerStyle(20);
    h_tau_endcap_res->SetMarkerSize(1.5);
    h_tau_endcap_res->SetMarkerColor(kBlue);
    h_tau_endcap_res->SetLineWidth(2);
    h_tau_endcap_res->Draw("E same");

    auto legend2 = new TLegend(0.5,0.75,0.9,0.85);
    legend2->SetBorderSize(0);
    legend2->SetNColumns(2);

    legend2->AddEntry(h_jet_barrel_res,"Jets Barrel","apl");
    legend2->AddEntry(h_tau_barrel_res,"Taus Barrel","apl");
    legend2->AddEntry(h_jet_endcap_res,"Jets Endcap","apl");
    legend2->AddEntry(h_tau_endcap_res,"Taus Endcap","apl");
    legend2->Draw();
    texl->Draw("same");

    c2->Print("res_L1jetstaus.pdf", "pdf");
	c2->Print("res_L1jetstaus.png", "png");

}