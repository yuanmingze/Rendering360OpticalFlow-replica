#pragma once

extern "C"
{
    int sort_linux_float(float *data, const int data_number);
    int sort_linux_double(double *data, const int data_number);
    int sort_linux_int(int *data, const int data_number);

    // sort SortFace
    // @param index_number: the
    int sortface_linux(unsigned int *index, const int index_number,
                       unsigned int *code, const int code_number,
                       unsigned long long *originalFace, const int originalFace_number);
}
