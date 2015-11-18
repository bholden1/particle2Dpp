#include "bee-map.h"
#include "global.h"
#include "logBook.h"
#include <vector>

using namespace std;

typedef struct particle {
    pose2D pose;
    float weight;
} particle;

typedef struct step {
    pose2D current;
    pose2D previous;
} step;

typedef struct lidarData {
    float ranges[NUM_RANGES];
} lidarData;

class Map {
public:
    Map();
    ~Map();
    
    // Load map_type
    void init_map(map_type map);
    void init_particles(int numParticles);
    
    // Prediction Phase
    void update_location(step motion);
    
    // Update Phase 
    void update_prediction(lidarData data);

private:
    map_type _map;
    int _numParticles;
    particle* _particles;
    
    // Update the particle's weight
    float _get_particle_weight(lidarData data, particle p);
    
    // Return the state with the highest probability
    pose2D _get_estimated_state(); 
    
    // Sample 0 mean gaussian with variance sigma;
    float _sample_with_variance(float sigma);
    
    // Get total probability of the map
    float total_probability();
};