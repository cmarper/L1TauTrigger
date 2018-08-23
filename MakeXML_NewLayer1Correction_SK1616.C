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

void MakeXML(TString InfileCalib = "", TString InfileIso = "", TString Outfile = "")
{
  std::ifstream infile_calib_dummy(InfileCalib.Data());
  std::ifstream infile_calib(InfileCalib.Data());

  string line_temp;
  int number_of_lines_calib = 0;

  while (std::getline(infile_calib_dummy, line_temp))
    ++number_of_lines_calib;


  std::ifstream infile_iso_dummy(InfileIso.Data());
  std::ifstream infile_iso(InfileIso.Data());
  std::ifstream infile_iso2(InfileIso.Data());

  string line_iso_temp;
  int number_of_lines_iso = 0;

  while (std::getline(infile_iso_dummy, line_iso_temp))
    ++number_of_lines_iso;

  std::ofstream XMLFile (Outfile.Data());

  XMLFile << "<algo id=\"calol2\">" << endl;
  XMLFile << "<context id=\"MainProcessor\">" << endl;
  XMLFile << "  <param id=\"tauMaxEta\" type=\"uint\">0x0001C</param>" << endl;
  XMLFile << "  <param id=\"tauEnergyCalibLUT\" type=\"vector:uint\">" << endl;

  string line_calib;
  int i = 0;
  while(getline(infile_calib,line_calib))
    {
      i++;
      std::istringstream iss(line_calib);
      if(i!=number_of_lines_calib) XMLFile << "      " << line_calib << "," <<endl;
      else XMLFile << "      " << line_calib << "" <<endl;
    }

  XMLFile << "    </param>"<<endl;
  XMLFile << "    <param id=\"tauIsoLUT1\" type=\"vector:uint\">"<<endl;

  string line_iso;
  int i_iso = 0;
  while(getline(infile_iso,line_iso))
    {
      i_iso++;
      std::istringstream iss(line_iso);
      if(i_iso!=number_of_lines_iso) XMLFile << "      " << line_iso << "," <<endl;
      else XMLFile << "      " << line_iso << "" <<endl;
    }


  XMLFile << "    </param>"<<endl;
  XMLFile << "    <param id=\"tauIsoLUT2\" type=\"vector:uint\">"<<endl;

  string line_iso2;
  int i_iso2 = 0;
  while(getline(infile_iso2,line_iso2))
    {
      i_iso2++;
      std::istringstream iss(line_iso2);
      if(i_iso2!=number_of_lines_iso) XMLFile << "      " << line_iso2 << "," <<endl;
      else XMLFile << "      " << line_iso2 << "" <<endl;
    }

  XMLFile <<"    </param>"<<endl;
  XMLFile <<"  </context>"<<endl;
  XMLFile <<"</algo>"<<endl;


}
