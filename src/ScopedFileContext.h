//
// Created by exozg on 13/07/2025.
//

#ifndef SCOPEDFILECONTEXT_H
#define SCOPEDFILECONTEXT_H
#include <memory>

#include "FileContext.h"


class ScopedFileContext {
public:
    explicit ScopedFileContext(std::shared_ptr<FileContext> ctx) {
        FileContext::set(std::move(ctx));
    }

    ~ScopedFileContext() {
        FileContext::clear();
    }

    ScopedFileContext(const ScopedFileContext&) = delete;
    ScopedFileContext& operator=(const ScopedFileContext&) = delete;
};


#endif //SCOPEDFILECONTEXT_H
