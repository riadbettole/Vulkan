#pragma once

#include "lve_device.hpp"
//std
#include <string>
#include <vector>

namespace lve {
	struct PipelineConfigInfo {
					VkViewport viewport;
					VkRect2D scissor;
					VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
					VkPipelineRasterizationStateCreateInfo rasterizationInfo;
					VkPipelineMultisampleStateCreateInfo multisampleInfo;
					VkPipelineColorBlendAttachmentState colorBlendAttachment;
					VkPipelineColorBlendStateCreateInfo colorBlendInfo;
					VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
					VkPipelineLayout pipelineLayout = nullptr;
					VkRenderPass renderPass = nullptr;	
					uint32_t subpass = 0;
	};

	class Lve_pipeline {
   	public:
		Lve_pipeline(
		    LveDevice &device,
			const std::string& vertFilepath,
			const std::string& fragFilePath,
			const PipelineConfigInfo& configInfo);
		~Lve_pipeline();

		Lve_pipeline(const Lve_pipeline&) = delete;
		void operator=(const Lve_pipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const  std::string& filepath);

		void createGraphicsPipeline(
			const std::string& vertFilepath,
			const std::string& fragFilePath,
			const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		LveDevice& lveDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};	

}