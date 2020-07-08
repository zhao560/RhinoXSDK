Pod::Spec.new do |s|

s.name         = "RhinoXSDK"
s.version      = "1.0.1"
s.summary      = "搏牛工具"

s.homepage     = "https://github.com/zhao560/RhinoXSDK"

s.license      = "MIT"

s.author       = { "ZHAO" => "790368411@qq.com" }

s.platform     = :ios, "9.0"


s.source       = { :git => "https://github.com/zhao560/RhinoXSDK.git", :tag => s.version}

s.frameworks = 'UIKit', 'WebKit', 'Foundation'

s.vendored_frameworks =  ['Frameworks/RhinoXCore.framework']

#s.resource = ''

#s.dependency 'SSZipArchive', '~> 2.2.3'

end

