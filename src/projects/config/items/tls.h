//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Hyunjun Jang
//  Copyright (c) 2018 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include "../item.h"

namespace cfg
{
	struct Tls : public Item
	{
		ov::String GetCertPath() const
		{
			return _cert_path;
		}

		ov::String GetChainCertPath() const
		{
			return _chain_cert_path;
		}

		ov::String GetKeyPath() const
		{
			return _key_path;
		}

	protected:
		void MakeParseList() const override
		{
			RegisterValue("CertPath", &_cert_path);
			RegisterValue("ChainCertPath", &_chain_cert_path);
			RegisterValue("KeyPath", &_key_path);
		}

		ov::String _cert_path;
		ov::String _chain_cert_path;
		ov::String _key_path;
	};
}