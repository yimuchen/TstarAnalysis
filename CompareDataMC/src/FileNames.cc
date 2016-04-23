/*******************************************************************************
 *
 *  Filename    : FileNames.cc
 *  Description : Implementations for getting the files save locations
 *  Author      : Yi-Mu "Enoch" Chen [ ensc@hep1.phys.ntu.edu.tw ]
 *
*******************************************************************************/
#include <string>
#include <cstdlib>

using namespace std;

//------------------------------------------------------------------------------
//   Static constants
//------------------------------------------------------------------------------
static const string base_dir = getenv( "CMSSW_BASE");
static const string work_dir = base_dir + "/src/TstarAnalysis/CompareDataMC";
static string channel_name;

void SetChannelType( const string& x ) { channel_name = x; }
string GetChannel() { return channel_name; }

string GetChannelPlotLabel(){
   if( channel_name == "MuonSignal" ){
      return "#mu signal channel";
   }else if( channel_name == "ElectronSignal") {
      return "e signal channel";
   } else {
      return "Unknown channel";
   }
}

string GetJsonFile() { return work_dir + "/data/" + channel_name + ".json"; }
string ResultsDir() { return work_dir + "/results/" + channel_name + "/" ; }
string GetTexSummaryFile() { return ResultsDir() + "summary.tex" ; }
string GetKinematicPlotFile( const string& plot_name ) { return ResultsDir() + plot_name + ".png"; }

string GetRooFitPlot_Template_File(){ return ResultsDir() + "RooFit_MCTemplate" +  ".png"; }
string GetRooFitObj_Template_File(){ return ResultsDir() + "RooFit_MCTemplate" + ".root"; }

//------------------------------------------------------------------------------
//   Higgs Combine Related files
//------------------------------------------------------------------------------
static string method_name ;

void SetMethod( const string& x ) { method_name = x ; }

string GetMethod() { return method_name; }

string GetMethodLabel()
{
   if ( method_name == "Template") {
      return "(MC template)";
   } else if( method_name == "SimFit" ){
      return "(simultaneous fit)";
   } else {
      return "";
   }
}

string GetCardFile( const string& masspoint )
{
   char buffer[1024];
   sprintf( buffer, "%s/card_%s_%s.txt" ,
      ResultsDir().c_str(),
      GetMethod().c_str(),
      masspoint.c_str()
   );
   return buffer;
}

string GetRooObjFile()
{
   char buffer[1024];
   sprintf( buffer, "%s/roofitobj_%s.root",
      ResultsDir().c_str(),
      GetMethod().c_str()
   );
   return buffer;
}

string GetRooObjPlot( const string& tags )
{
   char buffer[1024];
   sprintf( buffer, "%s/roofitplots_%s_%s.png",
      ResultsDir().c_str(),
      GetMethod().c_str(),
      tags.c_str()
   );
   return buffer ;
}

//------------------------------------------------------------------------------
//   HC Related
//------------------------------------------------------------------------------
static string hc_method;

void SetHCMethod( const string& x ) { hc_method = x; }

string GetHCMethod() { return hc_method; }


string HCRawOutputFile( int mass )
{
   char buffer[1024];
   sprintf( buffer , "%s/higgsCombineTest.%s.mH%d.root",
      getenv("PWD"),
      GetHCMethod().c_str(),
      mass
   );
   return buffer;
}

string HCStoreFile( int mass )
{
   char buffer[1024];
   sprintf( buffer , "%s/higgscombine_%s_%s_%d.root" ,
      ResultsDir().c_str(),
      GetMethod().c_str(),
      GetHCMethod().c_str(),
      mass  );
   return buffer;
}

string LimitPlotFile()
{
   char buffer[1024];
   sprintf( buffer , "%s/limit_%s_%s.png",
      ResultsDir().c_str(),
      GetMethod().c_str(),
      GetHCMethod().c_str()
   );
   return buffer;
}

//------------------------------------------------------------------------------
//   Misc. Functions
//------------------------------------------------------------------------------
int GetSignalMass( const string& name )
{
   string ans_string;
   for( auto y : name ){
      if( y >= '0' && y <= '9'){
         ans_string.push_back(y);
      }
   }
   return stoi(ans_string);

}
