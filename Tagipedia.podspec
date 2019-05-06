Pod::Spec.new do |s|

  s.name         = "Tagipedia"
  s.version      = "2.0.2"
  s.summary      = "Tagipedia"
  s.homepage     = "https://www.tagipedia.com"
  s.license      = { :type => "Commercial" }
  s.author       = { "Tagipedia" => "info@tagipedia.com" }
  s.platform     = :ios
  s.ios.deployment_target = '9.0'
  s.source       = { :git => "https://github.com/tagipedia/tagipedia-ios.git", :tag => "#{s.version}" }
  s.source_files  = 'Tagipedia/Tagipedia.framework/Headers/*.h'
  s.vendored_frameworks = 'Tagipedia/Tagipedia.framework'
  s.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration', 'MobileCoreServices', 'CoreLocation', 'CoreBluetooth'
  s.requires_arc = true
  s.xcconfig  =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/Tagipedia"',
                 'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/Tagipedia"' }
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2018 Tagipedia, Inc. All rights reserved.
      LICENSE
  }

end
