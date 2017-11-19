#ifndef FTRL_LIBRARY_H
#define FTRL_LIBRARY_H


extern "C" {

typedef unsigned int uint;

struct csr_binary_matrix {
    uint *columns;
    uint *indptr;
    uint num_examples;
};

struct ftrl_params {
    float alpha;
    float beta;
    float l1;
    float l2;
};

struct ftrl_model {
    float n_intercept;
    float z_intercept;
    float w_intercept;

    float *n;
    float *z;
    float *w;

    uint num_features;
};

ftrl_model ftrl_init_model(ftrl_params &params, uint num_features);

float ftrl_fit(uint *values, uint len, float y, ftrl_params &params, ftrl_model *model);

float ftrl_fit_batch(csr_binary_matrix &X, float* target, uint num_examples,
                     ftrl_params &params, ftrl_model *model, bool shuffle);

float ftrl_predict(uint *values, uint len, ftrl_params &params, ftrl_model *model);

void ftrl_predict_batch(csr_binary_matrix &X, ftrl_params &params, ftrl_model *model,
                        float* result);

float log_loss(float y, float p);

float sigmoid(float x);

float sign(float x);

};

#endif