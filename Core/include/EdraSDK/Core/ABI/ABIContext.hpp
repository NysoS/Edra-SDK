#ifndef ABI_CONTEXT_HPP
#define ABI_CONTEXT_HPP

#include "EdraSDK/Core/EdraDef.hpp"
#include "EdraSDK/Core/Types.hpp"

namespace EdraSDK::ABI {
	template<typename ChildContextType>
	class ABIContext {
	public:
		EdraSDK::EdraModule create() {
			static_cast<ChildContextType*>()->create_impl();
		}

		void destroy() {
			static_cast<ChildContextType*>()->destroy_impl();
		}

	private:
		EdraSDK::EdraModule create_impl()
		{
			return mModule;
		}

		void destroy_impl()
		{
			//
		}

	protected:
		EdraSDK::EdraModule mModule = nullptr;
	};
}

#endif // !ABI_CONTEXT_HPP
