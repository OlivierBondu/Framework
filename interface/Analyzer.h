#ifndef ANALYZER_H
#define ANALYZER_H

#include <FWCore/PluginManager/interface/PluginFactory.h>
#include <FWCore/ParameterSet/interface/ParameterSet.h>
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/Run.h>
#include <FWCore/Framework/interface/LuminosityBlock.h>
#include <FWCore/Framework/interface/EventSetup.h>
#include <FWCore/Framework/interface/ConsumesCollector.h>
#include <FWCore/Utilities/interface/InputTag.h>

#include <cp3_llbb/Framework/interface/Category.h>
#include <cp3_llbb/Framework/interface/ProducersManager.h>
#include <cp3_llbb/TreeWrapper/interface/TreeWrapper.h>

#include <Math/Vector4D.h>

#include <vector>
#include <map>

typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiE4D<float>> LorentzVector;

namespace Framework {

    class Analyzer {
        public:
            Analyzer(const std::string& name, const ROOT::TreeGroup& tree_, const edm::ParameterSet& config):
                m_name(name),
                tree(tree_) {
                }

            virtual void analyze(const edm::Event&, const edm::EventSetup&, const ProducersManager&) = 0;
            virtual void doConsumes(const edm::ParameterSet&, edm::ConsumesCollector&& collector) {}

            virtual void registerCategories(CategoryManager& manager) {}

            virtual void beginJob() {}
            virtual void endJob() {}

            virtual void beginRun(const edm::Run&, const edm::EventSetup&) {}
            virtual void endRun(const edm::Run&, const edm::EventSetup&) {}

            virtual void beginLuminosityBlock(const edm::LuminosityBlock&, const edm::EventSetup&) {}
            virtual void endLuminosityBlock(const edm::LuminosityBlock&, const edm::EventSetup&) {}

        protected:
            std::string m_name;
            ROOT::TreeGroup tree;
    };

}

typedef edmplugin::PluginFactory<Framework::Analyzer* (const std::string&, const ROOT::TreeGroup&, const edm::ParameterSet&)> ExTreeMakerAnalyzerFactory;

#endif
