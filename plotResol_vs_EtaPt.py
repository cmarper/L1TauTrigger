from ROOT import *
import ROOT
import operator
import array


ROOT.gSystem.Load('libRooFit')

def SetLucaStyle ():
    #global LS
    LS = TStyle (gStyle) #copy some of the basics of defualt style...
    LS.SetName("LucaStyle")
    LS.SetTitle("Luca Style")

    # pad
    LS.SetOptStat(0)
    LS.SetTickLength(0.02,"X")
    LS.SetTickLength(0.02,"Y")
    LS.SetPadTickY(1)
    LS.SetPadTickX(1)
    LS.SetPadGridY(1);
    LS.SetPadGridX(1);
    #LS.SetPadTopMargin(0.05)
    LS.SetPadBottomMargin(0.13)
    LS.SetPadLeftMargin(0.16)
    
    LS.SetCanvasDefH(600)
    LS.SetCanvasDefW(600)

    # axis
    LS.SetTitleYOffset(1.4)
    LS.SetTitleXOffset(0.9)
    LS.SetLabelOffset(0.009, "XYZ")
    LS.SetTitleSize(0.050, "XYZ")

    # legend
    LS.SetLegendBorderSize(0)
    LS.SetLegendFont(62)
    #LS.SetLegendFillStyle(0) #NOT IMPLEMENTED in root

    # if histoType == 0:
    #     LS.SetMarkerStyle(8);
    #     LS.SetMarkerSize(0.8);

    LS.cd() 
    return LS

gROOT.SetBatch(True)
styl = SetLucaStyle()

fIn = TFile ("results/plotOutData_vsEtaPt_SingleMu_2018A_315252_315488.root")

c1 = TCanvas()

######################################## general for plotiting
leg = TLegend(0.6, 0.65, 0.8, 0.85)
leg.SetFillColor(kWhite)
leg.SetBorderSize(0)
leg.SetTextFont(43)
leg.SetTextSize(20)

#cmsTextFont     = 61  # font of the "CMS" label
cmsTextFont     = 42  # font of the "CMS" label
#cmsTextSize   = 0.05  # font size of the "CMS" label
cmsTextSize   = 0.76*0.05  # font size of the "CMS" label 
xpos  = 0.16
ypos  = 0.94
CMSbox       = ROOT.TLatex  (xpos, ypos         , "#bf{CMS} #it{Preliminary}")
CMSbox.SetNDC()
CMSbox.SetTextSize(cmsTextSize)
CMSbox.SetTextFont(cmsTextFont)
CMSbox.SetTextColor(kBlack)
CMSbox.SetTextAlign(13)
extraTextSize   = 0.8*cmsTextSize 
extraTextFont   = 52 
extraTextBox = ROOT.TLatex  (0.65, 0.35, "p_{T}^{#tau, offline} > 20 GeV")
extraTextBox.SetNDC()
extraTextBox.SetTextSize(extraTextSize)
extraTextBox.SetTextFont(extraTextFont)
extraTextBox.SetTextColor(kBlack)
extraTextBox.SetTextAlign(13)

#lumi = "4.763 fb^{-1} (13 TeV, 2017B)"                                                                 
#lumi = "9.714 fb^{-1} (13 TeV, 2017C)" 
#lumi = "4.324 fb^{-1} (13 TeV, 2017D)"
#lumi = "9.385 fb^{-1} (13 TeV, 2017E)"
#lumi = "12.689 fb^{-1} (13 TeV, 2017F)" 
#lumi = "40.875 fb^{-1} (13 TeV, 2017BCDEF)"
#lumi = "40.875 fb^{-1} (13 TeV)"
lumi = "315252-315488 (13 TeV, 2018)"
#lumi = "MC (13 TeV, 2017)"
lumibox = TLatex  (0.9, 0.91, lumi)       
lumibox.SetNDC()
lumibox.SetTextAlign(31)
lumibox.SetTextSize(cmsTextSize)
lumibox.SetTextFont(42)
lumibox.SetTextColor(kBlack)


title = "L1T #tau"
titlebox = TLatex  (0.26, 0.91, title)
titlebox.SetNDC()
titlebox.SetTextAlign(31)
titlebox.SetTextSize(extraTextSize)
titlebox.SetTextFont(42)
titlebox.SetTextColor(kBlack)


bar = "Barrel"
barbox = TLatex  (0.42, 0.65, bar)
barbox.SetNDC()
barbox.SetTextAlign(31)
barbox.SetTextSize(extraTextSize)
barbox.SetTextFont(42)
barbox.SetTextColor(kBlack)


end = "Endcaps"
endbox = TLatex  (0.73, .65, end)
endbox.SetNDC()
endbox.SetTextAlign(31)
endbox.SetTextSize(extraTextSize)
endbox.SetTextFont(42)
endbox.SetTextColor(kBlack)

comment = "Transition between EB and EE"
#comment = "Excluded"
commentbox = TLatex  (0.58, .65, comment)
commentbox.SetNDC()
commentbox.SetTextAlign(31)
commentbox.SetTextSize(extraTextSize)
commentbox.SetTextFont(42)
commentbox.SetTextColor(kBlack)
commentbox.SetTextAngle(90);

#TPaveText *l1 = new TPaveText(0.9,0,1.1,.5);
#TText *text = l1->AddText("text");
#text->SetTextAngle(90);
#text->SetTextAlign(22);
#l1->Draw();

######################################## general for plotiting


######## eta plot

hResol_eta = fIn.Get("hResol_eta")
hResol_eta.SetLineWidth(2)
hResol_eta.SetLineColor(kBlue)
hResol_eta.SetMarkerColor(kBlue)
hResol_eta.SetMarkerStyle(8)
hResol_eta.SetMarkerSize(0.8)
hResol_eta.SetBinContent(6, 0.5)
# c1.SetLogx()
# hResol_eta.SetTitle(";|#eta^{offline}|;online #tau E_{T} resolution")
hResol_eta.SetTitle(";|#eta^{#tau, offline}|;RMS / <E_{T}^{#tau, L1}/p_{T}^{#tau, offline}>")
hResol_eta.SetMinimum(0.15)
hResol_eta.SetMaximum(0.40)
hResol_eta.GetXaxis().SetTitleOffset(0.9)
hResol_eta.Draw("pe")

#line = TLine(1.479,.15,1.479,.4)
line = TLine(1.392,.153,1.392,.398)
line.SetLineWidth(32)
line.SetLineStyle(7)
line.SetLineColor(kGray)

line.Draw()
#titlebox.Draw()
lumibox.Draw()
CMSbox.Draw()
#extraTextBox.Draw()
barbox.Draw()
endbox.Draw()
commentbox.Draw()

# hResol_eta.GetXaxis().SetMoreLogLabels(True)
# hResol_eta.GetXaxis().SetNoExponent(True)
c1.Print("results/plots/resol_vs_eta_2018A_315252_315488.pdf", "pdf")
c1.Print("results/plots/resol_vs_eta_2018A_315252_315488.png", "png")


######## nvtx plot 

hResol_nvtx = fIn.Get("hResol_nvtx")
hResol_nvtx.SetLineWidth(2)
hResol_nvtx.SetLineColor(kBlue)
hResol_nvtx.SetMarkerColor(kBlue)
hResol_nvtx.SetMarkerStyle(8)
hResol_nvtx.SetMarkerSize(0.8)

#hResol_nvtx.SetTitle(";|#nvtx^{#tau, offline}|;RMS / <E_{T}^{#tau, L1}/p_{T}^{#tau, offline}>")
hResol_nvtx.SetTitle(";nvtx;<E_{T}^{#tau, L1}/p_{T}^{#tau, offline}>")
#hResol_nvtx.SetMinimum(0.15)
#hResol_nvtx.SetMaximum(0.40)
hResol_nvtx.SetMinimum(0.15)
hResol_nvtx.SetMaximum(2.0)
hResol_nvtx.GetXaxis().SetTitleOffset(0.9)
hResol_nvtx.Draw("pe")

line = TLine(1.479,.15,1.479,.4)
line.SetLineWidth(4)
line.SetLineStyle(7)

line.Draw()

lumibox.Draw()
CMSbox.Draw()
#extraTextBox.Draw()
#barbox.Draw()
#endbox.Draw()

c1.Print("results/plots/resol_vs_nvtx_2018A_315252_315488.pdf", "pdf")
c1.Print("results/plots/resol_vs_nvtx_2018A_315252_315488.png", "png")






######## pt plot -- all
hResol_pt = fIn.Get("hResol_pt")
hResol_pt.SetLineWidth(2)
hResol_pt.SetLineColor(kBlue)
hResol_pt.SetMarkerColor(kBlue)
hResol_pt.SetMarkerStyle(8)
hResol_pt.SetMarkerSize(0.8)
#c1.SetLogx()
# hResol_pt.SetTitle(";p_{T}^{offline} [GeV];online #tau E_{T} resolution")
hResol_pt.SetTitle(";p_{T}^{#tau, offline} [GeV];RMS / <E_{T}^{#tau, L1}/p_{T}^{#tau, offline}>")
hResol_pt.SetMinimum(0.15)
hResol_pt.SetMaximum(0.40)
hResol_pt.GetXaxis().SetRangeUser(30, 110)
hResol_pt.GetXaxis().SetTitleOffset(0.9)
hResol_pt.Draw("pe")
#hResol_pt.GetXaxis().SetMoreLogLabels(True)
hResol_pt.GetXaxis().SetNoExponent(True)
lumibox.Draw()
CMSbox.Draw()
#extraTextBox.Draw()

c1.Print("results/plots/resol_vs_pt_2018A_315252_315488.pdf", "pdf")
c1.Print("results/plots/resol_vs_pt_2018A_315252_315488.png", "png")


######## pt plot -- barr/endc
hResol_pt_barrel = fIn.Get("hResol_pt_barrel")
hResol_pt_endcap = fIn.Get("hResol_pt_endcap")

hResol_pt_barrel.SetLineWidth(2)
hResol_pt_barrel.SetLineColor(kBlack)
hResol_pt_barrel.SetMarkerColor(kBlack)
hResol_pt_barrel.SetMarkerStyle(8)
hResol_pt_barrel.SetMarkerSize(0.8)

hResol_pt_endcap.SetLineWidth(2)
hResol_pt_endcap.SetLineColor(kRed)
hResol_pt_endcap.SetMarkerColor(kRed)
hResol_pt_endcap.SetMarkerStyle(8)
hResol_pt_endcap.SetMarkerSize(0.8)

#c1.SetLogx()
hResol_pt_barrel.SetTitle(";p_{T}^{#tau, offline} [GeV];online #tau E_{T} resolution")
hResol_pt_barrel.SetTitle(";p_{T}^{#tau, offline} [GeV];RMS / <E_{T}^{#tau, L1}/p_{T}^{#tau, offl}>")
hResol_pt_barrel.SetMinimum(0.12)
hResol_pt_barrel.SetMaximum(0.40)
miin = min (hResol_pt_barrel.GetMinimum(), hResol_pt_endcap.GetMinimum())
maax = max (hResol_pt_barrel.GetMaximum(), hResol_pt_endcap.GetMaximum())
#hResol_pt_barrel.SetMinimum(0.5*miin)
#hResol_pt_barrel.SetMaximum(1.1*maax)
hResol_pt_barrel.GetXaxis().SetTitleOffset(0.9)
hResol_pt_barrel.GetXaxis().SetRangeUser(30, 110)
hResol_pt_barrel.Draw("pe")
#hResol_pt_barrel.GetXaxis().SetMoreLogLabels(True)
hResol_pt_barrel.GetXaxis().SetNoExponent(True)
hResol_pt_endcap.Draw("pe same")
leg = TLegend(0.6, 0.65, 0.8, 0.85)
leg.SetFillColor(kWhite)
leg.SetBorderSize(0)
leg.SetTextFont(43)
leg.SetTextSize(20)
leg.AddEntry(hResol_pt_barrel, "Barrel", "lp")
leg.AddEntry(hResol_pt_endcap, "Endcaps", "lp")
leg.Draw()
#titlebox.Draw()
lumibox.Draw()
CMSbox.Draw()
#extraTextBox.Draw()
c1.Print("results/plots/resol_vs_pt_barrendc_2018A_315252_315488.pdf", "pdf")
c1.Print("results/plots/resol_vs_pt_barrendc_2018A_315252_315488.png", "png")
