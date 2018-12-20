
#ifndef SORTABLE_H
#define SORTABLE_H

#define ArraySize 16
#include <inttypes.h>

struct SortableRef {
    uint64_t key, reference;
    friend bool operator>(const SortableRef& left, const SortableRef& right) {
        return left.key > right.key;
    }
    friend bool operator==(const SortableRef& left, const SortableRef& right) {
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
struct SortableRef_JumpXchg {
    uint64_t key, reference;
    friend bool operator>(const SortableRef_JumpXchg& left, const SortableRef_JumpXchg& right) {
        return left.key > right.key;
    }
    friend bool operator==(const SortableRef_JumpXchg& left, const SortableRef_JumpXchg& right) {
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
struct SortableRef_FourCmovTemp {
    uint64_t key, reference;
    friend bool operator>(const SortableRef_FourCmovTemp& left, const SortableRef_FourCmovTemp& right) {
        return left.key > right.key;
    }
    friend bool operator==(const SortableRef_FourCmovTemp& left, const SortableRef_FourCmovTemp& right) {
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
struct SortableRef_SixCmovVolatileTemp {
    uint64_t key, reference;
    friend bool operator>(const SortableRef_SixCmovVolatileTemp& left, const SortableRef_SixCmovVolatileTemp& right) {
        return left.key > right.key;
    }
    friend bool operator==(const SortableRef_SixCmovVolatileTemp& left, const SortableRef_SixCmovVolatileTemp& right) {
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
struct SortableRef_SixCmovRegisterTemp {
    uint64_t key, reference;
    friend bool operator>(const SortableRef_SixCmovRegisterTemp& left, const SortableRef_SixCmovRegisterTemp& right) {
        return left.key > right.key;
    }
    friend bool operator==(const SortableRef_SixCmovRegisterTemp& left, const SortableRef_SixCmovRegisterTemp& right) {
        return left.key == right.key;
    }
};



struct SortableRef_ClangVersion {
    uint64_t key, reference;
    friend bool operator>(const SortableRef_ClangVersion& left, const SortableRef_ClangVersion& right) {
        return left.key > right.key;
    }
    friend bool operator==(const SortableRef_ClangVersion& left, const SortableRef_ClangVersion& right) {
        return left.key == right.key;
    }
};

#endif