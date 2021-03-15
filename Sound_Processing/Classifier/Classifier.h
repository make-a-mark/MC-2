#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class SVM {
                public:
                    /**
                    * Predict class for features vector
                    */
                    float predict(float *x) {
                        float kernels[26] = { 0 };
                        float decisions[1] = { 0 };
                        int votes[2] = { 0 };
                        kernels[0] = compute_kernel(x,   96.379997  , 46.639999  , 25.08  , 25.599998  , 35.099998  , 48.700001  , 61.419998  , 66.659996  , 61.959999  , 63.939999  , 61.0  , 56.879997  , 45.779999  , 52.459999  , 40.299999  , 47.739998  , 31.139999  , 33.959999  , 24.279999  , 26.099998  , 19.48  , 17.719999  , 17.359999  , 24.539999  , 10.219999  , 14.02  , 13.04  , 11.44  , 7.24  , 3.62  , 3.62  , 3.62  , 16.98  , 25.08  , 18.459999  , 21.4  , 18.459999  , 28.959999  , 21.4  , 16.98  , 15.78  , 14.92  , 15.78  , 14.92  , 13.54  , 11.44  , 10.219999  , 12.0  , 12.0  , 10.86  , 12.54  , 13.04  , 16.18  , 17.719999  , 18.1  , 19.139999  , 19.139999  , 19.48  , 18.1  , 17.719999  , 16.98  , 15.78  , 14.02  , 13.04 );
                        kernels[1] = compute_kernel(x,   45.5  , 46.5  , 59.699997  , 54.779999  , 49.639999  , 45.919998  , 40.299999  , 28.26  , 20.139999  , 14.02  , 7.24  , 8.08  , 8.86  , 12.54  , 13.54  , 14.02  , 14.92  , 14.92  , 14.48  , 14.02  , 12.54  , 10.86  , 8.86  , 8.86  , 5.1  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 5.1  , 7.24  , 8.86  , 9.559999  , 8.86  , 6.26  , 0.0  , 0.0  , 3.62  , 6.26  , 9.559999  , 10.219999  , 12.0  , 10.219999  , 7.24  , 8.86  , 7.24  , 6.26  , 5.1  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 5.1  , 5.1 );
                        kernels[2] = compute_kernel(x,   42.52  , 30.92  , 23.74  , 12.0  , 5.1  , 5.1  , 8.08  , 6.26  , 10.219999  , 6.26  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 0.0  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 5.1  , 5.1  , 5.1  , 6.26  , 6.26  , 6.26  , 6.26  , 6.26  , 5.1  , 6.26  , 6.26  , 5.1  , 5.1  , 5.1  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 0.0  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0 );
                        kernels[3] = compute_kernel(x,   72.220001  , 24.539999  , 30.279999  , 37.259998  , 38.82  , 36.559998  , 36.559998  , 33.360001  , 30.5  , 29.619999  , 23.74  , 22.299999  , 19.139999  , 14.02  , 11.44  , 27.32  , 30.279999  , 16.18  , 7.24  , 10.86  , 12.0  , 11.44  , 10.86  , 8.86  , 5.1  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 3.62  , 5.1  , 7.24  , 8.86  , 9.559999  , 7.24  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 3.62  , 3.62 );
                        kernels[4] = compute_kernel(x,   45.200001  , 49.899998  , 53.32  , 53.559998  , 55.599998  , 48.279999  , 48.559998  , 41.579998  , 31.139999  , 26.599998  , 19.48  , 13.54  , 7.24  , 5.1  , 8.08  , 10.219999  , 10.86  , 10.86  , 10.86  , 12.0  , 12.0  , 12.0  , 12.0  , 11.44  , 8.86  , 6.26  , 5.1  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 5.1  , 6.26  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 0.0  , 0.0  , 0.0 );
                        kernels[5] = compute_kernel(x,   226.259995  , 233.220001  , 106.720001  , 149.539993  , 132.179993  , 155.720001  , 166.119995  , 169.459991  , 178.179993  , 196.839996  , 200.619995  , 200.800003  , 207.139999  , 211.339996  , 211.440002  , 216.979996  , 222.699997  , 206.279999  , 172.419998  , 151.5  , 148.020004  , 150.039993  , 146.440002  , 158.519989  , 134.779999  , 125.719994  , 123.5  , 106.899994  , 96.379997  , 74.540001  , 51.32  , 37.619999  , 20.139999  , 16.98  , 14.48  , 12.54  , 8.86  , 7.24  , 7.24  , 10.219999  , 12.54  , 14.92  , 17.719999  , 16.98  , 16.98  , 19.139999  , 18.1  , 20.459999  , 16.18  , 20.779999  , 14.02  , 18.459999  , 13.54  , 13.04  , 12.54  , 12.54  , 13.54  , 14.02  , 16.98  , 14.92  , 14.92  , 15.78  , 13.04  , 8.86 );
                        kernels[6] = compute_kernel(x,   44.18  , 46.919998  , 49.360001  , 54.18  , 53.32  , 47.48  , 50.02  , 50.68  , 47.739998  , 41.099998  , 33.559998  , 29.84  , 24.539999  , 21.719999  , 20.139999  , 18.1  , 12.0  , 7.24  , 6.26  , 5.1  , 3.62  , 3.62  , 5.1  , 5.1  , 6.26  , 7.24  , 7.24  , 7.24  , 6.26  , 5.1  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 5.1  , 5.1  , 7.24  , 7.24  , 8.08  , 8.86  , 8.86  , 8.86  , 8.86  , 9.559999  , 8.86  , 8.08  , 8.86  , 8.86  , 7.24  , 7.24  , 6.26  , 5.1  , 5.1  , 5.1  , 3.62  , 3.62 );
                        kernels[7] = compute_kernel(x,   44.779999  , 15.78  , 14.48  , 26.099998  , 33.360001  , 29.84  , 35.459999  , 36.200001  , 38.139999  , 37.439999  , 33.360001  , 29.179998  , 27.08  , 21.1  , 18.799999  , 15.339999  , 11.44  , 8.08  , 6.26  , 3.62  , 3.62  , 3.62  , 5.1  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 3.62  , 5.1  , 6.26  , 6.26  , 6.26  , 6.26  , 6.26  , 6.26  , 7.24  , 6.26  , 6.26  , 6.26  , 6.26  , 6.26  , 5.1  , 5.1  , 5.1  , 5.1  , 3.62  , 3.62  , 3.62  , 3.62 );
                        kernels[8] = compute_kernel(x,   40.459999  , 45.059998  , 39.98  , 43.279999  , 40.619999  , 37.959999  , 33.360001  , 25.599998  , 16.98  , 10.219999  , 3.62  , 3.62  , 7.24  , 6.26  , 3.62  , 0.0  , 5.1  , 8.08  , 10.219999  , 12.54  , 12.54  , 8.86  , 6.26  , 3.62  , 0.0  , 0.0  , 0.0  , 3.62  , 5.1  , 5.1  , 6.26  , 7.24  , 7.24  , 7.24  , 8.08  , 7.24  , 7.24  , 8.08  , 7.24  , 6.26  , 7.24  , 6.26  , 6.26  , 5.1  , 5.1  , 5.1  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0 );
                        kernels[9] = compute_kernel(x,   114.18  , 203.399994  , 171.940002  , 120.5  , 99.540001  , 114.82  , 105.479996  , 98.540001  , 77.400002  , 69.720001  , 70.580002  , 62.18  , 57.68  , 51.32  , 32.98  , 19.48  , 15.78  , 17.359999  , 22.299999  , 18.799999  , 9.559999  , 6.26  , 6.26  , 5.1  , 3.62  , 6.26  , 9.559999  , 10.86  , 12.0  , 12.54  , 12.0  , 11.44  , 14.92  , 15.339999  , 14.48  , 14.92  , 16.58  , 16.18  , 16.58  , 16.58  , 15.339999  , 14.02  , 14.02  , 14.48  , 14.02  , 13.54  , 13.04  , 12.0  , 12.0  , 12.54  , 12.54  , 12.54  , 13.54  , 13.54  , 12.54  , 13.54  , 13.04  , 12.0  , 13.04  , 12.0  , 11.44  , 10.86  , 10.86  , 9.559999 );
                        kernels[10] = compute_kernel(x,   79.479996  , 196.319992  , 34.139999  , 88.360001  , 108.899994  , 103.739998  , 91.799995  , 84.959999  , 84.419998  , 84.419998  , 85.739998  , 77.979996  , 75.080002  , 74.439995  , 73.580002  , 75.759995  , 69.540001  , 63.32  , 57.799999  , 51.439999  , 44.48  , 39.139999  , 32.380001  , 31.34  , 27.08  , 25.08  , 24.82  , 24.82  , 22.02  , 16.98  , 12.54  , 8.86  , 9.559999  , 9.559999  , 8.08  , 9.559999  , 11.44  , 14.48  , 15.78  , 19.139999  , 23.18  , 26.599998  , 27.799999  , 28.719999  , 29.4  , 30.5  , 32.779999  , 34.34  , 35.099998  , 36.559998  , 36.919998  , 35.459999  , 34.34  , 32.579998  , 29.84  , 27.32  , 25.34  , 22.879999  , 20.779999  , 19.48  , 18.1  , 16.58  , 16.18  , 15.339999 );
                        kernels[11] = compute_kernel(x,   60.139999  , 8.86  , 22.879999  , 7.24  , 5.1  , 5.1  , 12.0  , 17.719999  , 22.02  , 24.0  , 24.0  , 24.279999  , 20.779999  , 20.139999  , 17.719999  , 14.02  , 15.339999  , 14.02  , 9.559999  , 10.219999  , 8.08  , 10.219999  , 6.26  , 7.24  , 3.62  , 5.1  , 5.1  , 6.26  , 5.1  , 0.0  , 0.0  , 5.1  , 6.26  , 7.24  , 8.08  , 7.24  , 6.26  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 3.62  , 3.62  , 5.1  , 5.1  , 6.26  , 6.26  , 7.24  , 7.24  , 8.08  , 8.08  , 8.08  , 8.08  , 8.08  , 8.08  , 8.08  , 8.08  , 8.86  , 10.219999  , 10.219999 );
                        kernels[12] = compute_kernel(x,   45.919998  , 64.040001  , 68.099998  , 44.619999  , 42.98  , 39.82  , 44.619999  , 34.52  , 19.82  , 13.04  , 8.08  , 6.26  , 6.26  , 5.1  , 5.1  , 5.1  , 3.62  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 5.1  , 5.1  , 5.1  , 5.1  , 5.1  , 3.62  , 5.1  , 5.1  , 3.62  , 0.0  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0 );
                        kernels[13] = compute_kernel(x,   40.619999  , 41.739998  , 43.119999  , 45.779999  , 37.259998  , 32.579998  , 38.639999  , 39.48  , 26.34  , 18.459999  , 12.54  , 8.86  , 6.26  , 3.62  , 0.0  , 8.08  , 8.86  , 5.1  , 0.0  , 5.1  , 10.86  , 13.54  , 13.54  , 12.54  , 10.219999  , 7.24  , 5.1  , 0.0  , 0.0  , 0.0  , 3.62  , 6.26  , 8.08  , 8.86  , 9.559999  , 10.219999  , 10.86  , 12.0  , 12.54  , 12.54  , 12.54  , 12.0  , 11.44  , 10.86  , 10.86  , 10.219999  , 9.559999  , 8.86  , 8.08  , 7.24  , 7.24  , 6.26  , 6.26  , 5.1  , 5.1  , 3.62  , 3.62  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0 );
                        kernels[14] = compute_kernel(x,   50.939999  , 45.5  , 42.98  , 42.52  , 42.68  , 44.619999  , 44.18  , 40.939999  , 40.619999  , 31.559999  , 26.599998  , 21.1  , 15.78  , 11.44  , 8.86  , 6.26  , 5.1  , 3.62  , 5.1  , 3.62  , 9.559999  , 11.44  , 13.54  , 14.48  , 14.48  , 12.54  , 13.04  , 12.0  , 13.04  , 12.54  , 13.04  , 12.54  , 12.0  , 10.219999  , 8.86  , 8.86  , 7.24  , 6.26  , 5.1  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 5.1  , 7.24  , 6.26  , 6.26  , 7.24  , 8.86  , 9.559999  , 9.559999  , 10.219999  , 10.219999  , 10.219999 );
                        kernels[15] = compute_kernel(x,   42.98  , 36.559998  , 29.84  , 30.059999  , 29.84  , 26.599998  , 26.84  , 29.4  , 34.52  , 34.52  , 28.039999  , 32.18  , 20.459999  , 19.139999  , 17.359999  , 15.78  , 18.459999  , 23.74  , 9.559999  , 9.559999  , 8.86  , 5.1  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0 );
                        kernels[16] = compute_kernel(x,   53.199997  , 47.48  , 33.759998  , 31.139999  , 37.439999  , 39.98  , 41.579998  , 40.779999  , 40.459999  , 45.779999  , 47.200001  , 46.919998  , 52.939999  , 54.539997  , 53.82  , 45.919998  , 39.98  , 35.639999  , 35.099998  , 31.559999  , 30.279999  , 29.84  , 27.559999  , 20.459999  , 16.18  , 13.54  , 12.0  , 10.219999  , 7.24  , 5.1  , 8.08  , 5.1  , 5.1  , 5.1  , 9.559999  , 6.26  , 8.08  , 7.24  , 8.86  , 6.26  , 8.86  , 6.26  , 5.1  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 5.1  , 3.62  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0 );
                        kernels[17] = compute_kernel(x,   79.799995  , 71.659996  , 36.559998  , 33.759998  , 44.48  , 42.68  , 44.779999  , 46.5  , 37.439999  , 36.200001  , 28.719999  , 22.6  , 18.459999  , 14.92  , 9.559999  , 7.24  , 8.08  , 8.08  , 13.04  , 14.02  , 17.719999  , 16.18  , 17.359999  , 16.18  , 14.92  , 14.48  , 13.54  , 11.44  , 10.219999  , 8.08  , 5.1  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 5.1  , 6.26  , 6.26  , 6.26  , 5.1  , 5.1  , 5.1  , 5.1  , 7.24  , 8.86  , 9.559999  , 8.86  , 8.08  , 8.86  , 12.0  , 11.44  , 10.219999  , 8.86  , 7.24  , 8.08  , 8.86  , 9.559999  , 8.86  , 8.08  , 7.24  , 6.26  , 6.26 );
                        kernels[18] = compute_kernel(x,   81.979996  , 108.059998  , 52.579998  , 54.059998  , 47.48  , 56.879997  , 69.540001  , 67.720001  , 63.119999  , 66.459999  , 65.159996  , 60.459999  , 59.359997  , 54.419998  , 58.039997  , 38.139999  , 17.359999  , 10.86  , 6.26  , 5.1  , 3.62  , 0.0  , 0.0  , 3.62  , 6.26  , 9.559999  , 10.219999  , 12.0  , 13.04  , 13.04  , 11.44  , 8.08  , 3.62  , 0.0  , 0.0  , 5.1  , 5.1  , 6.26  , 7.24  , 7.24  , 6.26  , 7.24  , 8.08  , 8.86  , 9.559999  , 9.559999  , 9.559999  , 9.559999  , 9.559999  , 8.86  , 8.86  , 8.86  , 8.86  , 8.08  , 8.08  , 8.08  , 7.24  , 7.24  , 7.24  , 7.24  , 6.26  , 6.26  , 6.26  , 6.26 );
                        kernels[19] = compute_kernel(x,   42.52  , 45.5  , 50.539997  , 51.84  , 50.799999  , 48.02  , 44.48  , 35.639999  , 26.84  , 18.799999  , 14.48  , 8.08  , 8.08  , 6.26  , 9.559999  , 12.0  , 11.44  , 14.92  , 12.54  , 14.92  , 13.54  , 12.54  , 10.219999  , 6.26  , 3.62  , 0.0  , 3.62  , 8.86  , 11.44  , 13.04  , 14.48  , 14.92  , 14.92  , 14.02  , 13.04  , 12.0  , 11.44  , 10.86  , 10.86  , 10.219999  , 10.86  , 10.219999  , 10.219999  , 10.219999  , 10.219999  , 9.559999  , 8.86  , 8.08  , 7.24  , 7.24  , 6.26  , 5.1  , 5.1  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0 );
                        kernels[20] = compute_kernel(x,   54.059998  , 14.02  , 14.92  , 17.359999  , 16.58  , 22.6  , 35.639999  , 54.66  , 64.760002  , 65.459999  , 59.799999  , 52.699997  , 51.84  , 55.719997  , 54.899998  , 46.360001  , 25.08  , 13.04  , 10.86  , 7.24  , 0.0  , 5.1  , 10.219999  , 18.459999  , 17.359999  , 15.339999  , 14.02  , 10.219999  , 10.219999  , 8.08  , 7.24  , 6.26  , 8.08  , 7.24  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 5.1  , 5.1  , 7.24  , 9.559999  , 10.86  , 10.219999  , 10.219999  , 8.08  , 8.86  , 8.86  , 8.86  , 8.08  , 7.24  , 6.26  , 5.1  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0 );
                        kernels[21] = compute_kernel(x,   40.139999  , 39.32  , 35.82  , 29.84  , 21.1  , 14.48  , 6.26  , 16.58  , 17.359999  , 10.219999  , 3.62  , 13.54  , 16.18  , 16.58  , 13.54  , 15.339999  , 12.54  , 12.54  , 9.559999  , 8.86  , 9.559999  , 8.08  , 5.1  , 3.62  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 3.62  , 3.62  , 5.1  , 5.1  , 5.1  , 5.1  , 6.26  , 6.26  , 6.26  , 6.26  , 8.08  , 7.24  , 5.1  , 5.1  , 5.1  , 3.62  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62 );
                        kernels[22] = compute_kernel(x,   51.959999  , 30.059999  , 37.619999  , 44.18  , 50.799999  , 54.059998  , 54.18  , 51.579998  , 40.939999  , 29.619999  , 22.299999  , 17.359999  , 11.44  , 8.08  , 11.44  , 7.24  , 15.339999  , 15.78  , 15.78  , 15.339999  , 13.04  , 12.0  , 11.44  , 8.86  , 7.24  , 6.26  , 3.62  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 5.1  , 5.1  , 5.1  , 5.1  , 5.1  , 5.1  , 6.26  , 7.24  , 9.559999  , 10.219999  , 11.44  , 14.02  , 15.339999  , 12.0  , 7.24  , 5.1  , 3.62  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 6.26  , 8.08  , 10.219999  , 12.0 );
                        kernels[23] = compute_kernel(x,   74.799995  , 34.52  , 32.98  , 43.879997  , 40.939999  , 36.919998  , 35.459999  , 39.98  , 33.759998  , 25.08  , 26.84  , 24.0  , 15.78  , 9.559999  , 8.08  , 6.26  , 8.86  , 13.04  , 14.02  , 16.18  , 18.1  , 11.44  , 16.18  , 13.04  , 14.02  , 7.24  , 7.24  , 8.08  , 6.26  , 3.62  , 5.1  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 5.1  , 6.26  , 6.26  , 8.08  , 8.08  , 8.08  , 8.86  , 8.86  , 8.08  , 10.219999  , 11.44  , 10.86  , 9.559999  , 8.86  , 8.86  , 10.86  , 13.54  , 14.92  , 16.18  , 16.18  , 15.339999  , 13.04  , 10.219999 );
                        kernels[24] = compute_kernel(x,   40.139999  , 36.559998  , 34.719997  , 33.18  , 26.599998  , 18.799999  , 13.04  , 9.559999  , 8.86  , 5.1  , 12.0  , 21.1  , 24.82  , 21.1  , 22.6  , 24.0  , 25.08  , 23.459999  , 22.299999  , 20.459999  , 18.799999  , 16.18  , 14.92  , 14.48  , 12.0  , 10.219999  , 9.559999  , 8.86  , 8.08  , 7.24  , 5.1  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 3.62  , 3.62  , 3.62  , 3.62  , 3.62  , 5.1  , 6.26  , 7.24  , 7.24  , 8.08  , 8.08  , 8.08  , 8.08  , 8.86  , 9.559999  , 10.219999  , 10.219999  , 10.219999  , 10.219999 );
                        kernels[25] = compute_kernel(x,   40.779999  , 25.599998  , 19.82  , 11.44  , 10.86  , 10.86  , 7.24  , 3.62  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0  , 0.0 );
                        float decision = 0.549422475913;
                        decision = decision - ( + kernels[0] * -1.160068e-06  + kernels[1] * -7.18675e-06  + kernels[2] * -7.9705296e-05  + kernels[3] * -8.133019e-06  + kernels[4] * -1.0790776e-05  + kernels[5] * -2.20106e-07  + kernels[6] * -9.309762e-06  + kernels[7] * -1.6891083e-05  + kernels[8] * -4.5082542e-05  + kernels[9] * -5.24713e-07  + kernels[10] * -2.49416e-07  + kernels[11] * -6.990228e-06 );
                        decision = decision - ( + kernels[12] * 1.0520159e-05  + kernels[13] * 1.1123457e-05  + kernels[14] * 2.250871e-06  + kernels[15] * 1.6313992e-05  + kernels[16] * 2.7977e-06  + kernels[17] * 7.419835e-06  + kernels[18] * 2.73573e-07  + kernels[19] * 2.5534462e-05  + kernels[20] * 4.322427e-06  + kernels[21] * 1.4027739e-05  + kernels[22] * 6.411941e-06  + kernels[23] * 7.2721e-06  + kernels[24] * 2.85345e-06  + kernels[25] * 7.5122053e-05 );

                        return decision > 0 ? 0 : 1;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(float classIdx) {
                        if (classIdx > 0) {
                            if (classIdx < 1)
                                return "play -- Unconfident";
                            else
                                return "play -- confident";
                        } else if (classIdx < 0) {
                            if (classIdx < -1) 
                                return "pause -- Confident";
                            else
                                return "pause -- Unconfident";
                        }
                        switch (classIdx) {
                            case 0:
                            return "pause";
                            case 1:
                            return "play";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                    /**
                    * Compute kernel between feature vector and support vector.
                    * Kernel type: poly
                    */
                    float compute_kernel(float *x, ...) {
                        va_list w;
                        va_start(w, 64);
                        float kernel = 0.0;

                        for (uint16_t i = 0; i < 64; i++) {
                            kernel += x[i] * va_arg(w, double);
                        }

                        return pow((0.1 * kernel) + 0.0, 2);
                    }
                };
            }
        }
    }