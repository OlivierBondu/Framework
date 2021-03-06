#ifndef JETS_PRODUCER
#define JETS_PRODUCER

#include <cp3_llbb/Framework/interface/CandidatesProducer.h>

#include <DataFormats/PatCandidates/interface/Jet.h>

class JetsProducer: public CandidatesProducer<pat::Jet> {
    public:
        JetsProducer(const std::string& name, const ROOT::TreeGroup& tree, const edm::ParameterSet& config):
            CandidatesProducer(name, tree, config)
        {

        }

        virtual ~JetsProducer() {}

        virtual void doConsumes(const edm::ParameterSet& config, edm::ConsumesCollector&& collector) override {
            m_jets_token = collector.consumes<std::vector<pat::Jet>>(config.getUntrackedParameter<edm::InputTag>("jets", edm::InputTag("slimmedJets")));
        }

        virtual void produce(edm::Event& event, const edm::EventSetup& eventSetup) override;

    private:

        // Tokens
        edm::EDGetTokenT<std::vector<pat::Jet>> m_jets_token;

        // Tree members
};

#endif
