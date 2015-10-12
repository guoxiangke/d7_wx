(function() {
    var config = {kitId: 'lto6uku',scriptTimeout: 3000};
    jQuery('html').addClass('wf-loading');
    var t = setTimeout(function() {
        jQuery('html').removeClass('wf-loading').addClass('wf-inactive');
    }, config.scriptTimeout);

})();
function selectorSupported(selector) {
    var support, link, sheet, doc = document, root = doc.documentElement, head = root.getElementsByTagName('head')[0], impl = doc.implementation || {hasFeature: function() {
            return false;
        }}, link = doc.createElement("style");
    link.type = 'text/css';
    (head || root).insertBefore(link, (head || root).firstChild);
    sheet = link.sheet || link.styleSheet;
    if (!(sheet && selector))
        return false;
    support = impl.hasFeature('CSS2', '') ? function(selector) {
        try {
            sheet.insertRule(selector + '{ }', 0);
            sheet.deleteRule(sheet.cssRules.length - 1);
        } catch (e) {
            return false;
        }
        return true;
    } : function(selector) {
        sheet.cssText = selector + ' { }';
        return sheet.cssText.length !== 0 && !(/unknown/i).test(sheet.cssText) && sheet.cssText.indexOf(selector) === 0;
    };
    return support(selector);
}
;
function css_support(property) 
{
    var div = document.createElement('div'), reg = new RegExp("(khtml|moz|ms|webkit|)" + property, "i");
    for (s in div.style) {
        if (s.match(reg))
            return true;
    }
    return false;
}
jQuery(document).ready(function($) {
    $(".home-play-video-button").bind('click', function() {
        var parent = $('#home-main');
        parent.find('.home-orginal').fadeTo(300, 0, function() {
            $(this).hide();
        });
        $('#top-container').animate({height: '865'}, 300, function() {
            video_playing = true;
            parent.find('.home-video').fadeTo('slow', 1);
            player.playVideo();
        });
    });
    $('.pro-upgrade .upgrade-page-link').change(function(event) {
        console.log($('option:selected', this).attr('data-action'));
        $(this).parent().find('.action').hide();
        $(this).parent().find('.' + $('option:selected', this).attr('data-action')).show();
    });
    $('.pro-upgrade .go-pro, .pro-upgrade .arrow').click(function(event) {
        event.preventDefault();
        window.location.href = $(this).parents('.site-chooser').find('.upgrade-page-link').val();
    });
    if ($('body').hasClass('page-template page-template-template_pro-php')) {
        $('#pro-features-slider-container').swiper({centeredSlides: true,slidesPerView: 'auto',autoplay: 2000,resistance: false,grabCursor: true,loop: true,loopedSlides: 10,});
    }
    if (window.navigator.platform.indexOf('Win') === 0)
        $('body').addClass('windows');
    else if (window.navigator.platform.indexOf('Mac') === 0)
        $('body').addClass('mac');
    else if (window.navigator.platform.indexOf('Linux') === 0)
        $('body').addClass('windows');
    $('#top-panel .menu-login > a').click(function(e) {
        e.preventDefault();
        e.stopPropagation();
        $(this).closest('li').toggleClass('current show-sub-menu');
    });
    $('#top-panel .sub-menu').click(function(e) {
        e.stopPropagation();
    });
    $('body').click(function(e) {
        if ($('#top-panel .menu-login').hasClass('show-sub-menu'))
            $('#top-panel .menu-login').removeClass('current show-sub-menu');
    });
    if (!('placeholder' in document.createElement('input'))) {
        $('input[placeholder]').each(function() {
            if ($(this).val() == '') {
                $(this).addClass('placeholder-active').val($(this).attr('placeholder'));
            }
            if ($(this).attr('type') == 'password') {
                $(this).addClass('placeholder-password');
            }
            $(this).focus(function() {
                if ($(this).hasClass('placeholder-active')) {
                    $(this).removeClass('placeholder-active').val('').focus();
                }
            }).blur(function() {
                if ($(this).val() == '') {
                    $(this).addClass('placeholder-active').val($(this).attr('placeholder'));
                }
            });
        });
        $('form').submit(function() {
            $(this).find('input.placeholder-active').val('');
        });
    }
    $('.regbar select').each(function() {
        var name = $(this).attr('name');
        $(this).wrap('<span class="select-custom select-' + name + '" />');
        var selected = $(this).find('option:selected').text();
        $(this).after('<span class="value">' + selected + '</span>');
        $(this).change(function() {
            var selected = $(this).find('option:selected').text();
            $(this).siblings('.value').text(selected);
        });
    });
    $('label.checkbox input[type=checkbox]').change(function() {
        if ($(this).is(':checked')) {
            $(this).closest('label.checkbox').addClass('checkbox-checked');
        } else {
            $(this).closest('label.checkbox').removeClass('checkbox-checked');
        }
    });
    var skip_slide = false;
    var slide_int = false;
    function switch_slide(index, scroll, selector, active_class, child) {
        var select_active = $(selector + '.' + active_class);
        var select_index = $(selector + ':eq(' + index + ')');
        if (!css_support('transition')) {
            (child ? select_active.find(child) : select_active).stop(true).fadeOut(500);
            (child ? select_index.find(child) : select_index).stop(true).delay(500).fadeIn(1000);
        }
        select_active.removeClass(active_class);
        select_index.addClass(active_class);
    }
    function rotate_slide(selector, active_class, child) {
        if (skip_slide) 
        {
            skip_slide = false;
            return;
        }
        var total = $(selector).size(), index = $(selector + '.' + active_class).index();
        if (index + 1 >= total)
            index = -1;
        switch_slide(index + 1, false, selector, active_class, child);
    }
    if ($('ul.main-testimonials').size() == 1) {
        if (!css_support('transition')) {
            $('ul.main-testimonials li').css('opacity', '1').css('display', 'none');
            $('ul.main-testimonials li.active').show();
        }
        $(window).load(function() {
            slide_int = setInterval(function() {
                rotate_slide('ul.main-testimonials li', 'active', '')
            }, 9000);
        });
    }
    if ($('#feature-slider').size() == 1) {
        var is_target = selectorSupported(':target');
        var target = window.location.hash;
        if (!css_support('animation')) {
            $('#feature-slider .slider').find('.slider-left, .slider-right').css('opacity', '1').css('display', 'none');
            if (target && $(target).is('.slider')) {
                $('#feature-slider ' + target).find('.slider-left, .slider-right').css('display', 'block');
                if (!is_target)
                    $('#feature-slider ' + target).addClass('slider-active');
            }
            $('#feature-slider .slider a.slider-nav').bind('click', function(e) {
                var slider = $(this).closest('.slider');
                $('#feature-slider .slider').not(slider).find('.slider-left, .slider-right').stop(true).fadeOut(500);
                slider.find('.slider-left, .slider-right').stop(true).delay(500).fadeIn(1000);
                if (!is_target) {
                    $('#feature-slider .slider').not(slider).removeClass('slider-active');
                    slider.addClass('slider-active');
                }
            });
        }
        if (!target || !$(target).is('.slider')) {
            $('#feature-slider .slider:eq(0)').addClass('slider-active');
            if (!is_target || !css_support('animation')) {
                $('#feature-slider .slider:eq(0)').find('.slider-left, .slider-right').css('display', 'block');
            }
            $('#feature-slider, #player').click(function(e) {
                skip_slide = true;
                clearInterval(slide_int);
            });
            $('#feature-slider .slider a.slider-nav').bind('click', function(e) {
                if (is_target)
                    $('#feature-slider .slider-active').removeClass('slider-active');
            });
            $(window).load(function() {
            });
        }
    }
    if (!css_support('transition')) {
        $('#sidebar').animate({opacity: 0.5}, 300).hover(function() {
            $(this).animate({opacity: 1}, 300);
        }, function() {
            $(this).animate({opacity: 0.5}, 300);
        });
    }
    $(window).load(fix_baseline);
});
var baseline = 24;
function fix_baseline() {
    jQuery('.post-content img').each(function() {
        var height = jQuery(this).height();
        var margin = height % baseline;
        if (margin > 0)
            jQuery(this).css('margin-bottom', (baseline - margin) + 'px');
    });
    jQuery('.textwidget').each(function() {
        var height = jQuery(this).height();
        var margin = height % baseline;
        if (margin > 0)
            jQuery(this).height(height + baseline - margin);
    });
}
