#include "example_custom_list.h"

#include <algorithm>

#include "common.h"
#include "custom_list.h"
#include "linear_allocator.h"

/** @file
* @brief Function homework3::exampleCustomList
*/

namespace homework3 {
    void exampleCustomList() {
        {
            homework3::CustomList<Val> list{0, 1, 2, 3, 4, 5, 6, 7, 8};
            list.insert(9);

            homework3::CustomList<Val, homework3::LinearStatefulAllocator<Val, maxCount> > customList{0, 1, 2, 3, 100};
            for (auto i = 5; i < maxCount; ++i) {
                customList.insert(i);
            }

            auto str = [&customList]() {
                std::ostringstream log;
                for (const auto &it: customList) {
                    log << it << " ";
                }
                return log.str();
            };

            LOG(INFO) << "List initial state: " << str();

            std::replace(customList.begin(), customList.end(), 100, 4);

            LOG(INFO) << "List after replacement: " << str();
        }

        LOG(INFO) << "-\n";

    }
}