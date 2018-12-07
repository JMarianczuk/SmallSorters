
#ifndef SORTABLE_H
#define SORTABLE_H

#define ArraySize 16
#include <inttypes.h>

struct Sortable {
    uint64_t key;
    uint64_t reference;
    friend bool operator>(const Sortable& left, const Sortable& right) {
        return left.key > right.key;
    }
    friend bool operator==(const Sortable& left, const Sortable& right) {
        return left.key == right.key;
    }
};

struct Sortable_JumpXchg {
    uint64_t key;
    friend bool operator>(const Sortable_JumpXchg& left, const Sortable_JumpXchg& right) {
        return left.key > right.key;
    }
    friend bool operator==(const Sortable_JumpXchg& left, const Sortable_JumpXchg& right) {
        return left.key == right.key;
    }
};

struct Sortable_TwoCmovTemp {
    uint64_t key;
    friend bool operator>(const Sortable_TwoCmovTemp& left, const Sortable_TwoCmovTemp& right) {
        return left.key > right.key;
    }
    friend bool operator==(const Sortable_TwoCmovTemp& left, const Sortable_TwoCmovTemp& right) {
        return left.key == right.key;
    }
};

struct Sortable_ThreeCmovVolatileTemp {
    uint64_t key;
    friend bool operator>(const Sortable_ThreeCmovVolatileTemp& left, const Sortable_ThreeCmovVolatileTemp& right) {
        return left.key > right.key;
    }
    friend bool operator==(const Sortable_ThreeCmovVolatileTemp& left, const Sortable_ThreeCmovVolatileTemp& right) {
        return left.key == right.key;
    }
};

struct Sortable_ThreeCmovRegisterTemp {
    uint64_t key;
    friend bool operator>(const Sortable_ThreeCmovRegisterTemp& left, const Sortable_ThreeCmovRegisterTemp& right) {
        return left.key > right.key;
    }
    friend bool operator==(const Sortable_ThreeCmovRegisterTemp& left, const Sortable_ThreeCmovRegisterTemp& right) {
        return left.key == right.key;
    }
};


#endif