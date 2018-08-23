 {

    const Int_t nbins = 4;
    float eta_edges[nbins+1] = { 0.0, 0.5, 1.0, 1.5, 2.1}; 
 
    float tau_20_30_mean[11] = { 1.120, 1.113, 1.126, 1.099};
    float tau_20_30_res[11] = { 23.3, 23.2, 24.3, 23.6 };

    float tau_30_40_mean[11] = {1.029, 1.023, 1.031, 1.016};
    float tau_30_40_res[11] = { 22.3, 22.5, 23.4, 22.6};

    float tau_40_60_mean[11] = {0.978, 0.974, 0.977, 0.987};
    float tau_40_60_res[11] = { 19.7, 20.0, 20.7, 18.7};

    float jet_20_30_mean[11] = { 1.171, 1.164, 1.136, 1.151};
    float jet_20_30_res[11] = { 33.4, 34.1, 33.5, 34.3};

    float jet_30_40_mean[11] = {1.335, 1.352, 1.318, 1.291};
    float jet_30_40_res[11] = { 25.3, 25.0, 26.3, 25.5};

    float jet_40_60_mean[11] = {1.324, 1.323, 1.302, 1.242};
    float jet_40_60_res[11] = { 19.9, 19.8, 20.3, 20.4};


    TH1F *h_tau_20_30_mean = new TH1F("h_tau_20_30_mean","h_tau_20_30_mean",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_tau_20_30_mean->AddBinContent(i+1,tau_20_30_mean[i]);
        h_tau_20_30_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_tau_20_30_res = new TH1F("h_tau_20_30_res","h_tau_20_30_res",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_tau_20_30_res->AddBinContent(i+1,tau_20_30_res[i]);
        h_tau_20_30_res->SetBinError(i+1,0.000001);
    }

    TH1F *h_tau_30_40_mean = new TH1F("h_tau_30_40_mean","h_tau_30_40_mean",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_tau_30_40_mean->AddBinContent(i+1,tau_30_40_mean[i]);
        h_tau_30_40_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_tau_30_40_res = new TH1F("h_tau_30_40_res","h_tau_30_40_res",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_tau_30_40_res->AddBinContent(i+1,tau_30_40_res[i]);
        h_tau_30_40_res->SetBinError(i+1,0.000001);
    }

    TH1F *h_tau_40_60_mean = new TH1F("h_tau_40_60_mean","h_tau_40_60_mean",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_tau_40_60_mean->AddBinContent(i+1,tau_40_60_mean[i]);
        h_tau_40_60_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_tau_40_60_res = new TH1F("h_tau_40_60_res","h_tau_40_60_res",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_tau_40_60_res->AddBinContent(i+1,tau_40_60_res[i]);
        h_tau_40_60_res->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_20_30_mean = new TH1F("h_jet_20_30_mean","h_jet_20_30_mean",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_jet_20_30_mean->AddBinContent(i+1,jet_20_30_mean[i]);
        h_jet_20_30_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_20_30_res = new TH1F("h_jet_20_30_res","h_jet_20_30_res",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_jet_20_30_res->AddBinContent(i+1,jet_20_30_res[i]);
        h_jet_20_30_res->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_30_40_mean = new TH1F("h_jet_30_40_mean","h_jet_30_40_mean",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_jet_30_40_mean->AddBinContent(i+1,jet_30_40_mean[i]);
        h_jet_30_40_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_30_40_res = new TH1F("h_jet_30_40_res","h_jet_30_40_res",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_jet_30_40_res->AddBinContent(i+1,jet_30_40_res[i]);
        h_jet_30_40_res->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_40_60_mean = new TH1F("h_jet_40_60_mean","h_jet_40_60_mean",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_jet_40_60_mean->AddBinContent(i+1,jet_40_60_mean[i]);
        h_jet_40_60_mean->SetBinError(i+1,0.000001);
    }

    TH1F *h_jet_40_60_res = new TH1F("h_jet_40_60_res","h_jet_40_60_res",nbins,eta_edges);
    for (int i=0; i<5; i++){ 
        h_jet_40_60_res->AddBinContent(i+1,jet_40_60_res[i]);
        h_jet_40_60_res->SetBinError(i+1,0.000001);
    }

    TPaveText* texl = new TPaveText(0.25,0.86,0.93,0.98,"NDC");
    texl->AddText("CMS Internal, #sqrt{s}=13 TeV, 2018 MC VBF H #rightarrow #tau#tau");
    texl->SetTextSize(0.03);
    texl->SetFillStyle(0);
    texl->SetBorderSize(0);
    

    TCanvas *c1 = new TCanvas("c1","c1",800,900);
    gStyle->SetOptStat(0);
    c1->cd();
    c1->SetGrid();

    h_tau_20_30_mean->SetLineColor(kRed);
    h_tau_20_30_mean->SetMarkerStyle(20);
    h_tau_20_30_mean->SetMarkerSize(1.7);
    h_tau_20_30_mean->SetMarkerColor(kRed);
    h_tau_20_30_mean->SetLineWidth(2);
    h_tau_20_30_mean->SetMaximum(1.5);
    h_tau_20_30_mean->SetMinimum(0.8);
    h_tau_20_30_mean->GetXaxis()->SetTitle("|#eta^{offline}| [GeV]");
    h_tau_20_30_mean->GetYaxis()->SetTitle("< E_{T}^{L1}/p_{T}^{offline} >");
    h_tau_20_30_mean->SetTitle(" ");
    h_tau_20_30_mean->Draw("E");

    h_tau_30_40_mean->SetLineColor(kRed);
    h_tau_30_40_mean->SetMarkerStyle(21);
    h_tau_30_40_mean->SetMarkerSize(1.7);
    h_tau_30_40_mean->SetMarkerColor(kRed);
    h_tau_30_40_mean->SetLineWidth(2);
    h_tau_30_40_mean->Draw("E same");

    h_tau_40_60_mean->SetLineColor(kRed);
    h_tau_40_60_mean->SetMarkerStyle(22);
    h_tau_40_60_mean->SetMarkerSize(1.9);
    h_tau_40_60_mean->SetMarkerColor(kRed);
    h_tau_40_60_mean->SetLineWidth(2);
    h_tau_40_60_mean->Draw("E same");

    h_jet_20_30_mean->SetLineColor(kBlue);
    h_jet_20_30_mean->SetMarkerStyle(20);
    h_jet_20_30_mean->SetMarkerSize(1.7);
    h_jet_20_30_mean->SetMarkerColor(kBlue);
    h_jet_20_30_mean->SetLineWidth(2);
    h_jet_20_30_mean->Draw("E same");

    h_jet_30_40_mean->SetLineColor(kBlue);
    h_jet_30_40_mean->SetMarkerStyle(21);
    h_jet_30_40_mean->SetMarkerSize(1.7);
    h_jet_30_40_mean->SetMarkerColor(kBlue);
    h_jet_30_40_mean->SetLineWidth(2);
    h_jet_30_40_mean->Draw("E same");

    h_jet_40_60_mean->SetLineColor(kBlue);
    h_jet_40_60_mean->SetMarkerStyle(22);
    h_jet_40_60_mean->SetMarkerSize(1.9);
    h_jet_40_60_mean->SetMarkerColor(kBlue);
    h_jet_40_60_mean->SetLineWidth(2);
    h_jet_40_60_mean->Draw("E same");

    auto legend1 = new TLegend(0.4,0.77,0.88,0.87);
    legend1->SetBorderSize(0);
    legend1->SetNColumns(2);

    legend1->AddEntry(h_tau_20_30_mean,"Taus: 20<p_{T}<30","apl");
    legend1->AddEntry(h_jet_20_30_mean,"Jets: 20<p_{T}<30","apl");
    legend1->AddEntry(h_tau_30_40_mean,"Taus: 30<p_{T}<40","apl");
    legend1->AddEntry(h_jet_30_40_mean,"Jets: 30<p_{T}<40","apl");
    legend1->AddEntry(h_tau_40_60_mean,"Taus: 40<p_{T}<60","apl");   
    legend1->AddEntry(h_jet_40_60_mean,"Jets: 40<p_{T}<60","apl");
    legend1->Draw();
    texl->Draw("same");

    c1->Print("mean_L1jetstaus_binsEta.pdf", "pdf");
    c1->Print("mean_L1jetstaus_binsEta.png", "png");
    
    TCanvas *c2 = new TCanvas("c2","c2",800,900);
    gStyle->SetOptStat(0);
    c2->cd();
    c2->SetGrid();

    h_tau_20_30_res->SetLineColor(kRed);
    h_tau_20_30_res->SetMarkerStyle(20);
    h_tau_20_30_res->SetMarkerSize(1.7);
    h_tau_20_30_res->SetMarkerColor(kRed);
    h_tau_20_30_res->SetLineWidth(2);
    h_tau_20_30_res->SetMaximum(36);
    h_tau_20_30_res->SetMinimum(17);
    h_tau_20_30_res->GetXaxis()->SetTitle("|#eta^{offline}| [GeV]");
    h_tau_20_30_res->GetYaxis()->SetTitle("RMS / < E_{T}^{L1}/p_{T}^{offline} >");
    h_tau_20_30_res->SetTitle(" ");
    h_tau_20_30_res->Draw("E");

    h_tau_30_40_res->SetLineColor(kRed);
    h_tau_30_40_res->SetMarkerStyle(21);
    h_tau_30_40_res->SetMarkerSize(1.7);
    h_tau_30_40_res->SetMarkerColor(kRed);
    h_tau_30_40_res->SetLineWidth(2);
    h_tau_30_40_res->Draw("E same");

    h_tau_40_60_res->SetLineColor(kRed);
    h_tau_40_60_res->SetMarkerStyle(22);
    h_tau_40_60_res->SetMarkerSize(1.9);
    h_tau_40_60_res->SetMarkerColor(kRed);
    h_tau_40_60_res->SetLineWidth(2);
    h_tau_40_60_res->Draw("E same");

    h_jet_20_30_res->SetLineColor(kBlue);
    h_jet_20_30_res->SetMarkerStyle(20);
    h_jet_20_30_res->SetMarkerSize(1.7);
    h_jet_20_30_res->SetMarkerColor(kBlue);
    h_jet_20_30_res->SetLineWidth(2);
    h_jet_20_30_res->Draw("E same");

    h_jet_30_40_res->SetLineColor(kBlue);
    h_jet_30_40_res->SetMarkerStyle(21);
    h_jet_30_40_res->SetMarkerSize(1.7);
    h_jet_30_40_res->SetMarkerColor(kBlue);
    h_jet_30_40_res->SetLineWidth(2);
    h_jet_30_40_res->Draw("E same");

    h_jet_40_60_res->SetLineColor(kBlue);
    h_jet_40_60_res->SetMarkerStyle(22);
    h_jet_40_60_res->SetMarkerSize(1.9);
    h_jet_40_60_res->SetMarkerColor(kBlue);
    h_jet_40_60_res->SetLineWidth(2);
    h_jet_40_60_res->Draw("E same");

    auto legend2 = new TLegend(0.4,0.65,0.88,0.75);
    legend2->SetBorderSize(0);
    legend2->SetNColumns(2);

    legend2->AddEntry(h_tau_20_30_res,"Taus: 20<p_{T}<30","apl");
    legend2->AddEntry(h_jet_20_30_res,"Jets: 20<p_{T}<30","apl");
    legend2->AddEntry(h_tau_30_40_res,"Taus: 30<p_{T}<40","apl");
    legend2->AddEntry(h_jet_30_40_res,"Jets: 30<p_{T}<40","apl");
    legend2->AddEntry(h_tau_40_60_res,"Taus: 40<p_{T}<60","apl");  
    legend2->AddEntry(h_jet_40_60_res,"Jets: 40<p_{T}<60","apl");
    legend2->Draw();
    texl->Draw("same");

    c2->Print("res_L1jetstaus_binsEta.pdf", "pdf");
    c2->Print("res_L1jetstaus_binsEta.png", "png");


}