//
// Created by exozg on 13/07/2025.
//

#ifndef FILECONTEXT_H
#define FILECONTEXT_H

#include <memory>
#include <stdexcept>
#include <span>

class FileContext {
    static std::shared_ptr<FileContext>& currentContext() {
        static std::shared_ptr<FileContext> ctx = nullptr;
        return ctx;
    }
public:
    class hxkFile* file;
    class hxkSection* section = nullptr;
    std::span<uint8_t> buffer;

    FileContext(hxkFile *file, const std::span<uint8_t> buffer)
        : file(file),
          buffer(buffer) {
    }

    static void set(std::shared_ptr<FileContext> ctx) {
        currentContext() = std::move(ctx);
    }

    static void clear() {
        currentContext().reset();
    }

    static std::shared_ptr<FileContext> get() {
        if (!currentContext()) {
            throw std::runtime_error("No active FileContext!");
        }
        return currentContext();
    }

};



#endif //FILECONTEXT_H
