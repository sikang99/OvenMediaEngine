//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Hyunjun Jang
//  Copyright (c) 2018 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include "tls.h"
#include "providers.h"
#include "publishers.h"
#include "applications.h"

namespace cfg
{
	struct Host : public Item
	{
		ov::String GetName() const
		{
			return _name;
		}

		ov::String GetIp() const
		{
			return _ip;
		}

		Tls GetTls() const
		{
			return _tls;
		}

		Providers GetProviders() const
		{
			return _providers;
		}

		Publishers GetPublishers() const
		{
			return _publishers;
		}

		const std::vector<Application> &GetApplications() const
		{
			return _applications.GetApplications();
		}

	protected:
		void MakeParseList() const override
		{
			RegisterValue("Name", &_name);
			RegisterValue<Optional>("IP", &_ip);
			RegisterValue<Optional, Includable>("TLS", &_tls);
			RegisterValue<Optional, Includable>("Providers", &_providers);
			RegisterValue<Optional, Includable>("Publishers", &_publishers);
			RegisterValue<Optional, Includable>("Applications", &_applications);
		}
		
		ov::String _name;
		ov::String _ip;
		Tls _tls;
		Providers _providers;
		Publishers _publishers;
		Applications _applications;
	};
}