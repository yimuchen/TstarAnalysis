from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'TSTARSELECT_TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_muchannel'
config.General.workArea = 'work_area'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = './run_production.py'

## Input parameters
config.JobType.pyCfgParams = [
   'Mode=0',
   ]

config.Data.inputDataset = '/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/MINIAODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 32
config.Data.outLFNDirBase = '/store/user/yichen/tstar_76X/'

config.Site.storageSite = 'T3_TW_NTU_HEP'
